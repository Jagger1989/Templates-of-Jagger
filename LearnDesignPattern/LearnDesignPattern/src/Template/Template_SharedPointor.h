#pragma once
#ifndef TEMPLATE_SHARED_POINTOR_H
#define TEMPLATE_SHARED_POINTOR_H

#include "../Utility/common.h"
#include <functional>
#include <memory>

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
    if (strP) // 将strP当作判断条件，判断其是否指向了一个对象
    {
    }
    std::string str = "abc";
    strP = std::make_shared<std::string>(str);

    *strP; //解引用，同普通指针

    strP->clear(); // 等同于  (*strP).clear();

    auto p = strP.get(); // 返回strP中保存的指针，
                         // 慎用，智能指针会自动释放内存，可能造成指向非法内存
    strP.swap(strP2); // 交换各自保存的指针, 等同于std::swap(strP, strP2);
    strP.unique(); // 判断引用计数是否唯一
    strP.use_count(); // 返回引用计数（主要用于调试）

    std::shared_ptr<std::string> p2 = std::make_shared<std::string>("abc");
    std::shared_ptr<std::string> p3 = std::make_shared<std::string>(10, 'c');

    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;

    auto p4(p3); // p3 p4 引用计数均+1，引用计数为0时释放内存
}

// std::auto_ptr
void test2()
{
    // auto_ptr可以自动释放资源，但是并非引用计数，copy时要小心
    std::auto_ptr<Investment> pInv(InvestmentFactory::createInvestment());
    std::auto_ptr<Investment> pInv2(pInv); // 此时被复制的pInv变成nullptr
    pInv = pInv2; //此时被复制的pInv2变为nullptr
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

// 自定义删除器
void test3()
{
    // unique_ptr需要在模板中传入函数类型
    std::unique_ptr<Investment, decltype (deleter)*> pInv(new Investment, deleter);

    std::shared_ptr<Investment> pInv2(new Investment, deleter);
}

// *****************************************************************************************//*
// 考虑以下情况                                                                              //*
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
    p->test(); // 调用成功，但其实内存已经释放掉了，这个成功是不明确行为！！所以慎用get()函数     //*
    if (nullptr != p)                                                                       //*
    {                                                                                       //*
        delete p; // 程序运行至此会抛异常                                                     //*
    }                                                                                       //*
    p = nullptr;                                                                            //*
}                                                                                           //*
                                                                                            //*
// *****************************************************************************************//*

#endif // !TEMPLATE_SHARED_POINTOR_H