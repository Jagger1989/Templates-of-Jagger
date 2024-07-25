#pragma once
#include <mutex>
#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class SingletonT
{
public:
    //Get instance
    template<typename ...Args>
    static std::shared_ptr<T> GetInstance(Args&&... args) {
        if (!m_instance) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (nullptr == m_instance) {
                m_instance = std::make_shared<T>(std::forward<Args>(args)...);
            }
        }
        return m_instance;
    }

    //Delete instance
    static void DelInstance() {
        // 在lock对象的生命周期内上锁，销毁时解锁，用于方便上锁操作
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_instance) {
            m_instance.reset();
            m_instance = nullptr;
        }
    }

private:
    SingletonT() = default;
    SingletonT(const SingletonT&) = delete;
    SingletonT& operator=(const SingletonT&) = delete;
    ~SingletonT() = default;

private:
    static std::shared_ptr<T> m_instance;
    static std::mutex m_mutex;
};

template<typename T>
std::shared_ptr<T> SingletonT<T>::m_instance = nullptr;

template<typename T>
std::mutex SingletonT<T>::m_mutex;

class MyClass1
{
public:
    MyClass1(const string& data) : data_(data)
    {
        cout << "MyClass " << data << " Constructed" << endl;
        //cout << data_.data() << endl;
    };

    virtual ~MyClass1()
    {
        cout << "MyClass Destructor" << endl;
    };

    void fun()
    {
        cout << "data = " << data_ << endl;
    }
private:
    string data_;
};

class MyClass2
{
public:
    MyClass2(const string& data) : data_(data)
    {
        cout << "MyClass2 " << data << " Constructed" << endl;
        //cout << data_.data() << endl;
    };

    virtual ~MyClass2()
    {
        cout << "MyClass Destructor" << endl;
    };

    void fun()
    {
        cout << "data = " << data_ << endl;
    }
private:
    string data_;
};
#include <deque>

int testSingleton()
{
    //SingletonT(std::shared_ptr方式)
    /*
    * 如果使用不同的泛型类型两次调用 GetInstance 函数，
    * 即使是同一个 SingletonT 类，它们实际上会创建两个不同类型的单例对象。
    * 每个不同类型的 SingletonT 实例都会维护自己的静态成员 m_instance，因此它们不会共享相同的单例对象。
    * 因此，即使使用相同的 SingletonT 类模板，
    * 只要使用不同的泛型类型参数调用 GetInstance，
    * 将会创建并维护两个独立的单例对象，而不是共享一个单例对象。
    */
    auto _inst = SingletonT<MyClass1>::GetInstance("111");
    _inst->fun();

    auto _inst2 = SingletonT<MyClass1>::GetInstance("222");
    _inst->fun();

    auto _inst3 = SingletonT<MyClass2>::GetInstance("222");
    _inst->fun();


    SingletonT<MyClass1>::DelInstance();
    SingletonT<MyClass2>::DelInstance();
    std::deque<int> dq;
    dq.pop_front();
    system("pause");
    return 1;
}


