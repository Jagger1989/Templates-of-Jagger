#ifndef STRING_P_HPP
#define STRING_P_HPP
#include "../Utility/common.h"

#include <string>
using namespace std;

/*
个人理解：
    插入选择insert()
    追加单个字符用push_back()
    追加字符串全部operator+=即可
    追加字符串某部分用灵活性更高的append()

    赋值字符串全部选择operator= 即可
    赋值字符串某部分用灵活性更高的assign()
*/

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

// insert()
void testString_p2()
{
    string str5("abcdef12345");
    string temp2 = "12345";
    str5.insert(2, temp2); // 注意在索引2 前 处插入temp2
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, temp2, 2, 3); // 在索引2前处插入temp2的索引2到3
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    string temp3 = "123456789";
    str5.insert(2, temp3, 3); // 插入temp3 从3开始到最后一位
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, 10, '*'); // 在2位插入10个*
    cout << str5 << endl;
    cout << "=========================" << endl;

    string str2 = "你好哇";
    str2.insert(1, "Y");; // 特别注意，ASCII中中文为双字节，英文单字节，此处会导致Y与你的前半字节结合导致乱码
    cout << str2 << endl;
    cout << "=========================" << endl;

    str2 = "你好哇";
    str2.insert(2, "Y");; // 特别注意，中文为双字节，英文单字节，此处不会乱码
    cout << str2 << endl;
    cout << "=========================" << endl;
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

// erase()
void testString_p4()
{
    string str1 = "abcde12345";
    str1.erase(2); // 删除2开始至最后，param2采用了默认值npos(param2意义是长度，这里猜测传入-1的特殊处理)
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(2, 4); // 注意此处是param1是起始索引，param2是长度！！！
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it = str1.begin();
    auto it11 = str1.erase(it); // 删除指定的迭代器位置元素，本例中删除a，结果位bcde12345，并且返回下一个元素迭代器
    cout << str1 << endl;
    cout << *it11 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it2 = str1.erase(it + 1, str1.end() - 1); // 删除区间的元素，前闭后开，并返回下一个元素的迭代器
    cout << str1 << endl;
    cout << *it2 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(0, 2);
    cout << str1 << endl;
    cout << "=========================" << endl;
}

// assign() 与 = 相比灵活性更高，可以选择性的赋值字符串的一部分
void testString_p5()
{
    string str1;
    string s = "12345";
    str1.assign("abcde12345");
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s, 2, 2); // 注意此处param2是起始索引，param3是长度
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(5, '*');
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s.begin()+1, s.end()); // 迭代器，前闭后开
    cout << str1 << endl;

    auto it = str1.begin();
    cout << *it << endl;
    it.operator++();
    cout << *it << endl;
}

// append() 与 operator+=相比灵活性更高
void testString_p6()
{
    string str1 = "abc";
    string temp = "ABCDE";
    str1.append(temp);
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(temp, 2, 3); // 注意此处param2是起始索引，param3是长度而非终了索引
    cout << str1 << endl;

    str1 = "abc";
    str1.append("ABCDE", 2, 3); // 注意此处param2是起始索引，param3是长度而非终了索引
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append("ABCDE", 2); // ※注意此处为前2个字符
    cout << str1 << endl;
    str1 = "abc";
    str1.append(string("ABCDE"), 2); // ※注意此处为从索引2开始至最后
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(5, 'A'); // 追加5个A
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(temp.begin() + 1, temp.end() - 1); // 注意此处为前闭后开, 注意迭代器性能低于索引
    cout << str1 << endl;
    cout << "=========================" << endl;
}

// push_back(), operator+=
void testString_p7()
{
    string str1("abcde12345");
    str1.push_back('x');
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1 += {'*', '%', '$'}; // +=初始化列表类型
    cout << str1 << endl;
    cout << "=========================" << endl;
}

// replace()
void testString_p8()
{
    //string& replace(size_t pos, size_t len, const string& str);
    string str1("abcde12345");
    const string temp("uvwxyz");
    str1.replace(2, 3, temp); // 注意此处param2是长度（索引参数基本都是起始索引+长度，并且前闭后闭）
    cout << str1 << endl;
    cout << "1=========================" << endl;

    //string& replace(iterator i1, iterator i2, const string& str);
    str1 = "abcde12345";
    str1.replace(str1.begin() + 1, str1.begin() + 3, temp); // 注意迭代器是前闭后开
    cout << str1 << endl;
    cout << "2=========================" << endl;

    //string& replace(size_t pos, size_t len, const string& str, size_t subposm size_t sublen);
    str1 = "abcde12345";
    str1.replace(2, 3, temp, 2, 3);
    cout << str1 << endl;
    cout << "3=========================" << endl;

    //string& replace(size_t pos, size_t len, size_t n, char c);
    str1 = "abcde12345";
    str1.replace(2, 3, 5, '*');
    cout << str1 << endl;
    cout << "4=========================" << endl;

    //string& replace(iterator i1, iterator i2, InputIterator first, InputIterator last);
    str1 = "abcde12345";
    str1.replace(str1.begin() + 1, str1.begin() + 2, temp.begin() + 1, temp.end());
    cout << str1 << endl;
    cout << "5=========================" << endl;
}

// find类函数
void testString_p9()
{
    string str("abcde12345abcde12345");
    size_t index = str.find("c"); // 没找到返回npos
    cout << index << endl;
    cout << "1=========================" << endl;

    index = str.rfind("c");
    cout << index << endl;
    cout << "2=========================" << endl;

    index = str.find_first_of("bc");
    cout << index << endl;
    cout << "3=========================" << endl;

    index = str.find_first_not_of("a");
    cout << index << endl;
    cout << "4=========================" << endl;

    index = str.find_last_of("c");
    cout << index << endl;
    cout << "5=========================" << endl;

    index = str.find_last_not_of("c");
    cout << index << endl;
    cout << "6=========================" << endl;
}

// substr()
void testString_p10()
{
    string str1("abcde12345");
    str1.substr(0, 1);
    cout << str1 << endl;
    cout << "1=========================" << endl;
}

// conmpare() 逐字符按ASCII比较
void testString_p11()
{
    string str1("abcde12345");
    string str2("abcde12345");
    string str3("accde12345");
    string str4("aacde12345");
    int ret = str1.compare(str2); // 相等返回0
    cout << ret << endl;
    cout << "1=========================" << endl;

    ret = str1.compare(str3);
    cout << ret << endl; // 小于返回-1
    cout << "2=========================" << endl;

    ret = str1.compare(str4);
    cout << ret << endl; // 小于返回1
    cout << "3=========================" << endl;
}

/*
strcpy和memcpy主要有以下3方面的区别。
1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy
*/
// copy()
void testString_p12()
{

}

// 其他字符串操作
void testString_p165()
{
    string str("abcde12345");
    const char* charPtr1 = str.c_str();
    const char* charPtr2 = str.data();
}


#endif // !STRING_P_HPP