#pragma once
#include "../Utility/common.h"
#include <mutex>


class Singleton_1;

// 标准实现
// 需要手动释放内存, 可以使用sharedPtr？
// 多线程情况无法保证唯一实例（加互斥锁？貌似可以保证唯一实例，但是运行效率低）
class Singleton_1
{
public:
    // 全局访问点
    static Singleton_1* getInstance()
    {
        // 如果是多线程需要考虑线程安全问题
        if (nullptr == m_instance)
        {
            m_instance = new Singleton_1();
        }
        return m_instance;
    }

    // 内存释放函数
    static void releaseInstance()
    {
        if (nullptr != m_instance)
        {
            delete m_instance;
            m_instance = nullptr;
        }
    }

private:
    Singleton_1()
    {
        ++m_count;
        printf("constructor count = %d\r\n", m_count);
    }
    Singleton_1(const Singleton_1&) = delete;
    Singleton_1& operator=(const Singleton_1&) = delete;

    ~Singleton_1()
    {
        releaseInstance();
    }

    static Singleton_1* m_instance;
    static int m_count;
};

Singleton_1* Singleton_1::m_instance = nullptr;
int Singleton_1::m_count = 0;

// 单线程最优选择
// Meyers Singleton Pattern
// 使用对象所以无需手动释放
// 多线程能保证唯一实例，但是无法确保原子性
// 构造函数的步骤 分配内存 -> 初始化成员变量
// 当第一条线程调用getInstance()时，可能内存分配完成但是成员没有来得及初始化，
// 这时第二条线程直接访问成员可能会导致成员定义不一致
class Singleton_2
{
public:
    static Singleton_2& getInstance()
    {
        static Singleton_2 instance;
        return instance;
    }

    // Iot的方式
    //static Singleton_2* getInstance()
    //{
    //    static Singleton_2 instance;
    //    return &instance;
    //}

private:
    Singleton_2()
    {
        ++m_count;
        printf("constructor count = %d\r\n", m_count);
    }

    ~Singleton_2() = default;
    Singleton_2(const Singleton_2&) = delete;
    Singleton_2& operator=(const Singleton_2&) = delete;

    static Singleton_1* m_instance;
    static std::mutex m_lock;
    static int m_count;
};

// https://www.bilibili.com/video/BV1nE41197nK?p=2&spm_id_from=pageDriver

extern "C" long __cdecl _InterlockedCompareExchange(long volatile * Dest, long Exchange, long Comp);
#pragma intrinsic (_InterlockedCompareExchange)

template <class T>
class Singleton_3
{
    using T_sharedPtr = std::shared_ptr<T>;
public:
    static T& getInstance()
    {
        // 注意需要加volatile
        static volatile long lock = 0;
        int ret = 0;
        // _InterlockedCompareExchange原子锁，运行效率高
        // 一个线程访问_InterlockedCompareExchange时会锁定lock的内存地址，其他线程无法同时访问，从而实现互斥
        // _InterlockedCompareExchange为 Win32 Windows SDK InterlockedCompareExchange函数提供编译器内部函数支持
        // 在 ARM 平台上，可以使用带 _acq 和 _rel 后缀的内部函数获取和发布语义，例如在临界区的起始位置。 ARM 内部 _nf ( "无防护" ) 后缀不能充当内存屏障。

        /*  _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand))
            比较_Destination与_Comparand，如果相等，那么将_Exchange赋值给_Destination，但是注意返回的是_Destination原来的值     */

        // 首条线程访问时，将lock设置为1，然后去执行构造对象，1标识了有线程在构造对象的状态，其他线程再访问会进入到循环中等待状态更新到2，
        // 进而保证了唯一实例
        if (ret == ::_InterlockedCompareExchange(&lock, 1, 0) != 0)
        {
            while (lock != 2)
                Sleep(0); // 释放拥有权，重新竞争
            return m_instance;
        }
        T_sharedPtr temp(new T(), T::Deleter());
        m_instance = temp;
        lock = 2;
        Log::logDebug("内存分配完成\r\n");
        return *m_instance.get();
    }

protected:
    Singleton_3()
    {
        Log::logDebug("Singleton_3 construct");
    }
    ~Singleton_3()
    {
        Log::logDebug("Singleton_3 destruct");
    }
    static T_sharedPtr m_instance;

private:
    class Deleter
    {
    public:
        // operator()代表函数调用操作符
        void operator()(T* p)
        {
            delete p;
        }
    };
};

#define DECLARE_SINGLETON_CLASS(type)\
    friend class Singleton_3<type>;
class Manager : public Singleton_3<Manager>
{
    //friend class Singleton_3<Manager>;
    DECLARE_SINGLETON_CLASS(Manager)
public:
    // 如果不是public智能指针会找不到
    ~Manager()
    {
        Log::logDebug("Manager destruct");
    }
    void print()
    {
        Log::logDebug("print count = " + m_count);
    }
protected:
    Manager()
    {
        Log::logDebug("Manager construct");
    }

private:
    static int m_count;
};

int Manager::m_count;

template<class T>
class Singleton_4
{
public:
    static T& getInstance()
    {
        return m_instance;
    }

protected:
    Singleton_4()
    {
        Log::logDebug("Singleton_4 construct");
    }

private:
    static T m_instance;
};

// 饿汉模式

// 饿汉模式具有潜在危险，会因为编译顺序导致一些不可预测风险，尽量避免使用

// 单例模式固定格式
//1、总是避免第三方调用拷贝构造函数以及赋值操作符
//2、总是避免第三方调用构造函数
//3、尽量避免第三方调用析构函数
//4、总是需要一个静态方法用于全局访问