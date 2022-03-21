#pragma once
#ifndef TEMPLATE_SHARED_POINTOR_H
#define TEMPLATE_SHARED_POINTOR_H

#include "../Utility/common.h"
#include <functional>
#include <memory>
using namespace std;
class Investment
{

};

class InvestmentFactory
{
public:
    static Investment* createInvestment()
    {
        return new Investment;
    }
};


// std::shared_ptr
void test1()
{
    std::shared_ptr<std::string> strP;
    std::shared_ptr<std::string> strP2;
    if (strP) // ��strP�����ж��������ж����Ƿ�ָ����һ������
    {
    }
    std::string str = "abc";
    strP = std::make_shared<std::string>(str);

    *strP; //�����ã�ͬ��ָͨ��

    strP->clear(); // ��ͬ��  (*strP).clear();

    auto p = strP.get(); // ����strP�б����ָ�룬
                         // ���ã�����ָ����Զ��ͷ��ڴ棬�������ָ��Ƿ��ڴ�
    strP.swap(strP2); // �������Ա����ָ��, ��ͬ��std::swap(strP, strP2);
    strP.unique(); // �ж����ü����Ƿ�Ψһ
    strP.use_count(); // �������ü�������Ҫ���ڵ��ԣ�

    std::shared_ptr<std::string> p2 = std::make_shared<std::string>("abc");
    std::shared_ptr<std::string> p3 = std::make_shared<std::string>(10, 'c');

    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;

    auto p4(p3); // p3 p4 ���ü�����+1�����ü���Ϊ0ʱ�ͷ��ڴ�
}

// std::auto_ptr
void test2()
{
    // auto_ptr�����Զ��ͷ���Դ�����ǲ������ü�����copyʱҪС��
    std::auto_ptr<Investment> pInv(InvestmentFactory::createInvestment());
    std::auto_ptr<Investment> pInv2(pInv); // ��ʱ�����Ƶ�pInv���nullptr
    pInv = pInv2; //��ʱ�����Ƶ�pInv2��Ϊnullptr
}

void deleter(Investment* _p)
{
    if (nullptr != _p)
    {
        delete _p;
    }
    _p = nullptr;
    std::cout << "deleter worked" << std::endl;
}

// �Զ���ɾ����
void test3()
{
    // unique_ptr��Ҫ��ģ���д��뺯������
    std::unique_ptr<Investment, decltype (deleter)*> pInv(new Investment, deleter);

    std::shared_ptr<Investment> pInv2(new Investment, deleter);
}

// *****************************************************************************************//*
// �����������                                                                              //*
class AAA                                                                                   //*
{                                                                                           //*
public:                                                                                     //*
    void test()                                                                             //*
    {                                                                                       //*
        printf("test\r\n");                                                                 //*
    }                                                                                       //*
                                                                                            //*
    ~AAA()                                                                                  //*
    {                                                                                       //*
        printf("AAA destructor\r\n");                                                       //*
    }                                                                                       //*
};                                                                                          //*
                                                                                            //*
void deleter22(AAA* _p)                                                                     //*
{                                                                                           //*
    if (nullptr != _p)                                                                      //*
    {                                                                                       //*
        printf("delete _p\r\n");                                                            //*
        delete _p;                                                                          //*
    }                                                                                       //*
    _p = nullptr;                                                                           //*
    printf("deleter22 worked\r\n");                                                         //*
}                                                                                           //*
                                                                                            //*
AAA* testMain0()                                                                            //*
{                                                                                           //*
    std::shared_ptr<AAA> p(new AAA, deleter22);                                             //*
    return p.get();                                                                         //*
}                                                                                           //*
                                                                                            //*
void testSharedPtr()                                                                        //*
{                                                                                           //*
    AAA* p = testMain0();                                                                   //*
    printf("step1\r\n");                                                                    //*
    p->test(); // ���óɹ�������ʵ�ڴ��Ѿ��ͷŵ��ˣ�����ɹ��ǲ���ȷ��Ϊ������������get()����     //*
    if (nullptr != p)                                                                       //*
    {                                                                                       //*
        delete p; // �����������˻����쳣                                                     //*
    }                                                                                       //*
    p = nullptr;                                                                            //*
}                                                                                           //*
                                                                                            //*
// *****************************************************************************************//*

// weak_ptr
// Ϊ�˸���shared_ptr�������һ������ָ�룬�����͹��첻��ı����ü���
// ���ڽ��shared_ptrѭ����������ڴ�й¶������

class SharedPtrTest2;
class SharedPtrTest1 {
public:
    void printRefCount()
    {
        std::cout << m_2ptr.use_count() << std::endl;
    }

    ~SharedPtrTest1()
    {
        cout << m_2ptr.use_count() << endl;
    }
private:
    std::shared_ptr<SharedPtrTest2> m_2ptr;
};

class SharedPtrTest2 {
public:
    void printRefCount()
    {
        std::cout << m_1ptr.use_count() << std::endl;
    }

    ~SharedPtrTest2()
    {
        cout << m_1ptr.use_count() << endl;
    }
private:
    std::shared_ptr<SharedPtrTest1> m_1ptr;
};

void testSharedPtr5()
{
    shared_ptr< SharedPtrTest1> p1 = std::shared_ptr< SharedPtrTest1>(new SharedPtrTest1);
    shared_ptr< SharedPtrTest2> p2 = std::shared_ptr< SharedPtrTest2>(new SharedPtrTest2);
}

#endif // !TEMPLATE_SHARED_POINTOR_H