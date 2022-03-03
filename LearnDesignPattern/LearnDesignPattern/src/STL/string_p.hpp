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
    str7.resize(40); // 修改字符串长度，不重新分配空间?待确认，实测capacity变大了
    cout << str7.size() << endl;
    cout << str7.length() << endl;
    cout << str7.capacity() << endl;
    cout << str7 << endl;

    cout << "str7.resize(5);" << endl;
    str7.resize(5); // 会截断字符串，此处只保留了前五个字符abcde
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
    str8.reserve(20); // 修改字符串空间，capacity实测变大了
    cout << str8.size() << endl;
    cout << str8.length() << endl;
    cout << str8.capacity() << endl;
    cout << str8 << endl;

    cout << "str8.reserve(5);" << endl;
    str8.reserve(5); // 会保留最小长度
    cout << str8.size() << endl;
    cout << str8.length() << endl;
    cout << str8.capacity() << endl; //capacity实测没有变小
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
    str2 += {'*', '%', '$'}; // +=初始化列表类型
    //cout << str2 << endl;
    //cout << "=========================" << endl;

    string str3("abcdef12345");
    str3.append("xxx");
    //cout << str3 << endl;
    //cout << "=========================" << endl;

    string str4("abcdef12345");
    //char* temp = "xxx"; // 编译报错，指向常量了
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
    str5.insert(2, temp3, 3); // 插入temp3 从3开始到最后一位
    //cout << str5 << endl;
    //cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, 10, '*'); // 在2位插入10个*
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
    str1.erase(2); // 删除2开始至最后
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(2, 4); // 删除2~4
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it = str1.begin();
    auto it11 = str1.erase(it); // 删除指定的迭代器位置元素，本例中删除a，结果位bcde12345，并且返回下一个元素迭代器
    cout << str1 << endl;
    cout << *it11 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it2 = str1.erase(it + 1, str1.end() - 1); // 删除区间的元素，前闭后开
    cout << str1 << endl;
    cout << *it2 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.pop_back(); // 删除最后一个元素，返回void
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
    str1.assign(s, 2, 4); // 并非是迭代器，是索引，并非是前闭后开
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(5, '*');
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s.begin()+1, s.end()); // 迭代器，前闭后开
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