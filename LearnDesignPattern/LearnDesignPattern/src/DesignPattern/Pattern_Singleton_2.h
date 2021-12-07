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
        //cout << "MyClass1 Constructor" << endl;
        cout << data_.data() << endl;
    };

    virtual ~MyClass1()
    {
        cout << "MyClass Destructor" << endl;
    };

    void fun()
    {
        cout << "this is fun." << endl;
    }
    void fun2()
    {
        cout << "this is fun2." << endl;
    }
private:
    string data_;
};


int main()
{
    std::cout << "Hello World!\n";

    //SingletonT(std::shared_ptr方式)
    auto _inst = SingletonT<MyClass1>::GetInstance("MyClass1 Constructor");
    SingletonT<MyClass1>::DelInstance();

    system("pause");
    return 1;
}


