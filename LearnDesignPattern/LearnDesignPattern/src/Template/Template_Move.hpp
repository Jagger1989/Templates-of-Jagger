#ifndef TEMPLATE_MOVE_H
#define TEMPLATE_MOVE_H
#include "../Utility/common.h"
#include <vector>

void testMove()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    cout << "str addr = " << &str << endl;
    // ʹ�� push_back(const T&) ���أ�
    // ��ʾ���ǽ��������� str �ĳɱ�
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // ʹ����ֵ���� push_back(T&&) ���أ�
    // ��ʾ�������ַ���������
    // str �����ݱ��ƶ��� vector
    // ��������Ƚϵͣ���Ҳ��ζ�� str ���ڿ���Ϊ�ա�
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "V[0] = " << v[0] << std::endl;
    std::cout << "V[0] addr = " << &v[0] << std::endl;
    std::cout << "V[1] = " << v[1] << std::endl;
    std::cout << "V[1] addr = " << &v[1] << std::endl;

    // ����֪����move��������һ���������ض��������£�ȡ�������������Դ��
    // ��Ҳ���Ǿ������ֵ���ã��������õı������ͷš�
    // move�������Ż���һ�ַ�ʽ
}

#endif // !TEMPLATE_MOVE_H