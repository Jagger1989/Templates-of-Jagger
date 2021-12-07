#pragma once
#ifndef TEMPLATE_SHARED_POINTOR_H
#define TEMPLATE_SHARED_POINTOR_H

#include "../Utility/common.h"


// ����ָ��
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
#endif // !TEMPLATE_SHARED_POINTOR_H