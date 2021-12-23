#pragma once
#include "../Utility/common.h"
#include <mutex>


class Singleton_1;

// ��׼ʵ��
// ��Ҫ�ֶ��ͷ��ڴ�, ����ʹ��sharedPtr��
// ���߳�����޷���֤Ψһʵ�����ӻ�������ò�ƿ��Ա�֤Ψһʵ������������Ч�ʵͣ�
class Singleton_1
{
public:
    // ȫ�ַ��ʵ�
    static Singleton_1* getInstance()
    {
        // ����Ƕ��߳���Ҫ�����̰߳�ȫ����
        if (nullptr == m_instance)
        {
            m_instance = new Singleton_1();
        }
        return m_instance;
    }

    // �ڴ��ͷź���
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

// ���߳�����ѡ��
// Meyers Singleton Pattern
// ʹ�ö������������ֶ��ͷ�
// ���߳��ܱ�֤Ψһʵ���������޷�ȷ��ԭ����
// ���캯���Ĳ��� �����ڴ� -> ��ʼ����Ա����
// ����һ���̵߳���getInstance()ʱ�������ڴ������ɵ��ǳ�Աû�����ü���ʼ����
// ��ʱ�ڶ����߳�ֱ�ӷ��ʳ�Ա���ܻᵼ�³�Ա���岻һ��
class Singleton_2
{
public:
    static Singleton_2& getInstance()
    {
        static Singleton_2 instance;
        return instance;
    }

    // Iot�ķ�ʽ
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
        // ע����Ҫ��volatile
        static volatile long lock = 0;
        int ret = 0;
        // _InterlockedCompareExchangeԭ����������Ч�ʸ�
        // һ���̷߳���_InterlockedCompareExchangeʱ������lock���ڴ��ַ�������߳��޷�ͬʱ���ʣ��Ӷ�ʵ�ֻ���
        // _InterlockedCompareExchangeΪ Win32 Windows SDK InterlockedCompareExchange�����ṩ�������ڲ�����֧��
        // �� ARM ƽ̨�ϣ�����ʹ�ô� _acq �� _rel ��׺���ڲ�������ȡ�ͷ������壬�������ٽ�������ʼλ�á� ARM �ڲ� _nf ( "�޷���" ) ��׺���ܳ䵱�ڴ����ϡ�

        /*  _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand))
            �Ƚ�_Destination��_Comparand�������ȣ���ô��_Exchange��ֵ��_Destination������ע�ⷵ�ص���_Destinationԭ����ֵ     */

        // �����̷߳���ʱ����lock����Ϊ1��Ȼ��ȥִ�й������1��ʶ�����߳��ڹ�������״̬�������߳��ٷ��ʻ���뵽ѭ���еȴ�״̬���µ�2��
        // ������֤��Ψһʵ��
        if (ret == ::_InterlockedCompareExchange(&lock, 1, 0) != 0)
        {
            while (lock != 2)
                Sleep(0); // �ͷ�ӵ��Ȩ�����¾���
            return m_instance;
        }
        T_sharedPtr temp(new T(), T::Deleter());
        m_instance = temp;
        lock = 2;
        Log::logDebug("�ڴ�������\r\n");
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
        // operator()���������ò�����
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
    // �������public����ָ����Ҳ���
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

// ����ģʽ

// ����ģʽ����Ǳ��Σ�գ�����Ϊ����˳����һЩ����Ԥ����գ���������ʹ��

// ����ģʽ�̶���ʽ
//1�����Ǳ�����������ÿ������캯���Լ���ֵ������
//2�����Ǳ�����������ù��캯��
//3���������������������������
//4��������Ҫһ����̬��������ȫ�ַ���