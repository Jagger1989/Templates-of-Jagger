#ifndef STRING_P_HPP
#define STRING_P_HPP
#include "../Utility/common.h"

#include <string>
using namespace std;

void testString_p1()
{
    string s("abcde12345");
    string str1(s);
    string str2(s, 2);
    string str3(s, 2, 5);
    string str4(5, 'c');
    string str5(s.begin(), s.end());
    //cout << str1 << endl;
    //cout << str2 << endl;
    //cout << str3 << endl;
    //cout << str4 << endl;
    //cout << str5 << endl;

    string::const_iterator it = s.begin();
    while (it != s.end())
    {
        //cout << *it << endl;
        ++it;
    }

    string str6("abcde12345");
    cout << str6.size() << endl;
    cout << str6.length() << endl;
    cout << str6.max_size() << endl;
    cout << str6.capacity() << endl;
    cout << str6 << endl;

    cout << "=========================" << endl;

    string str7("abcde12345");
    cout << str7.size() << endl;
    cout << str7.length() << endl;
    cout << str7.capacity() << endl;
    cout << str7 << endl;

    cout << "str7.resize(20);" << endl;
    str7.resize(40); // �޸��ַ������ȣ������·���ռ�?��ȷ�ϣ�ʵ��capacity�����
    cout << str7.size() << endl;
    cout << str7.length() << endl;
    cout << str7.capacity() << endl;
    cout << str7 << endl;

    cout << "str7.resize(5);" << endl;
    str7.resize(5); // ��ض��ַ������˴�ֻ������ǰ����ַ�abcde
    cout << str7.size() << endl;
    cout << str7.length() << endl;
    cout << str7.capacity() << endl;
    cout << str7 << endl;

    cout << "=========================" << endl;

    string str8("abcde12345");
    cout << str8.size() << endl;
    cout << str8.length() << endl;
    cout << str8.capacity() << endl;
    cout << str8 << endl;

    cout << "str8.reserve(20);" << endl;
    str8.reserve(20); // �޸��ַ����ռ䣬capacityʵ������
    cout << str8.size() << endl;
    cout << str8.length() << endl;
    cout << str8.capacity() << endl;
    cout << str8 << endl;

    cout << "str8.reserve(5);" << endl;
    str8.reserve(5); // �ᱣ����С����
    cout << str8.size() << endl;
    cout << str8.length() << endl;
    cout << str8.capacity() << endl; //capacityʵ��û�б�С
    cout << str8 << endl;
}

// operator+= push_back(), append(), insert()
void testString_p2()
{
    string str1("abcde12345");
    str1.push_back('x');
    //cout << str1 << endl;
    //cout << "=========================" << endl;

    string str2("abcde12345");
    str2 += {'*', '%', '$'}; // +=��ʼ���б�����
    //cout << str2 << endl;
    //cout << "=========================" << endl;

    string str3("abcdef12345");
    str3.append("xxx");
    //cout << str3 << endl;
    //cout << "=========================" << endl;

    string str4("abcdef12345");
    //char* temp = "xxx"; // ���뱨��ָ������
    const char* temp = "yyy";
    str4.append(temp);
    //cout << str4 << endl;
    //cout << "=========================" << endl;

    string str5("abcdef12345");
    string temp2 = "12345";
    str5.insert(2, temp2);
    //cout << str5 << endl;
    //cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, temp2, 2, 3);
    //cout << str5 << endl;
    //cout << "=========================" << endl;

    str5 = "abcdef12345";
    string temp3 = "123456789";
    str5.insert(2, temp3, 3); // ����temp3 ��3��ʼ�����һλ
    //cout << str5 << endl;
    //cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, 10, '*'); // ��2λ����10��*
    //cout << str5 << endl;
    //cout << "=========================" << endl;
}

// swap()
void testString_p3()
{
    string str1 = "abcde12345S";
    string str2 = "bbbbb00000";
    swap(str1, str2);
    cout << str1 << endl;
    cout << str2 << endl;
    str1.swap(str2);
    cout << str1 << endl;
    cout << str2 << endl;
}

// erase() pop_back()
void testString_p4()
{
    string str1 = "abcde12345";
    str1.erase(2); // ɾ��2��ʼ�����
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(2, 4); // ɾ��2~4
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it = str1.begin();
    auto it11 = str1.erase(it); // ɾ��ָ���ĵ�����λ��Ԫ�أ�������ɾ��a�����λbcde12345�����ҷ�����һ��Ԫ�ص�����
    cout << str1 << endl;
    cout << *it11 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it2 = str1.erase(it + 1, str1.end() - 1); // ɾ�������Ԫ�أ�ǰ�պ�
    cout << str1 << endl;
    cout << *it2 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.pop_back(); // ɾ�����һ��Ԫ�أ�����void
    cout << str1 << endl;
    cout << *it2 << endl;
    cout << "=========================" << endl;
}

// assign()
void testString_p5()
{
    string str1;
    string s = "12345";
    str1.assign("abcde12345");
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s, 2, 4); // �����ǵ���������������������ǰ�պ�
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(5, '*');
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s.begin()+1, s.end()); // ��������ǰ�պ�
    cout << str1 << endl;
}

void testString_p6()
{
    string str1 = "abcde12345";
    string temp = "xxx";
    str1.replace(2, 4, temp);
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1 = "abcde12345";
    str1.replace(str1.begin() + 2, str1.end(), temp);
    cout << str1 << endl;
}

void testString_p7()
{

}

#endif // !STRING_P_HPP