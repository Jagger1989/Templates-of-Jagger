#pragma once
#ifndef TEMPLATE_SHARED_POINTOR_H
#define TEMPLATE_SHARED_POINTOR_H

#include "../Utility/common.h"


// 智能指针
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
#endif // !TEMPLATE_SHARED_POINTOR_H