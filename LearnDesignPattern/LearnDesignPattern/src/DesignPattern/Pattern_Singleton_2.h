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
        // ��lock�������������������������ʱ���������ڷ�����������
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
    //SingletonT(std::shared_ptr��ʽ)
    /*
    * ���ʹ�ò�ͬ�ķ����������ε��� GetInstance ������
    * ��ʹ��ͬһ�� SingletonT �࣬����ʵ���ϻᴴ��������ͬ���͵ĵ�������
    * ÿ����ͬ���͵� SingletonT ʵ������ά���Լ��ľ�̬��Ա m_instance��������ǲ��Ṳ����ͬ�ĵ�������
    * ��ˣ���ʹʹ����ͬ�� SingletonT ��ģ�壬
    * ֻҪʹ�ò�ͬ�ķ������Ͳ������� GetInstance��
    * ���ᴴ����ά�����������ĵ������󣬶����ǹ���һ����������
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


