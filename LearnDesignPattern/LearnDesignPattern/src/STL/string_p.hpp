#ifndef STRING_P_HPP
#define STRING_P_HPP
#include "../Utility/common.h"

#include <string>
using namespace std;

/*
������⣺
    ����ѡ��insert()
    ׷�ӵ����ַ���push_back()
    ׷���ַ���ȫ��operator+=����
    ׷���ַ���ĳ����������Ը��ߵ�append()

    ��ֵ�ַ���ȫ��ѡ��operator= ����
    ��ֵ�ַ���ĳ����������Ը��ߵ�assign()
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

// insert()
void testString_p2()
{
    string str5("abcdef12345");
    string temp2 = "12345";
    str5.insert(2, temp2); // ע��������2 ǰ ������temp2
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, temp2, 2, 3); // ������2ǰ������temp2������2��3
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    string temp3 = "123456789";
    str5.insert(2, temp3, 3); // ����temp3 ��3��ʼ�����һλ
    cout << str5 << endl;
    cout << "=========================" << endl;

    str5 = "abcdef12345";
    str5.insert(2, 10, '*'); // ��2λ����10��*
    cout << str5 << endl;
    cout << "=========================" << endl;

    string str2 = "�����";
    str2.insert(1, "Y");; // �ر�ע�⣬ASCII������Ϊ˫�ֽڣ�Ӣ�ĵ��ֽڣ��˴��ᵼ��Y�����ǰ���ֽڽ�ϵ�������
    cout << str2 << endl;
    cout << "=========================" << endl;

    str2 = "�����";
    str2.insert(2, "Y");; // �ر�ע�⣬����Ϊ˫�ֽڣ�Ӣ�ĵ��ֽڣ��˴���������
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
    str1.erase(2); // ɾ��2��ʼ�����param2������Ĭ��ֵnpos(param2�����ǳ��ȣ�����²⴫��-1�����⴦��)
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(2, 4); // ע��˴���param1����ʼ������param2�ǳ��ȣ�����
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it = str1.begin();
    auto it11 = str1.erase(it); // ɾ��ָ���ĵ�����λ��Ԫ�أ�������ɾ��a�����λbcde12345�����ҷ�����һ��Ԫ�ص�����
    cout << str1 << endl;
    cout << *it11 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    auto it2 = str1.erase(it + 1, str1.end() - 1); // ɾ�������Ԫ�أ�ǰ�պ󿪣���������һ��Ԫ�صĵ�����
    cout << str1 << endl;
    cout << *it2 << endl;
    cout << "=========================" << endl;

    str1 = "abcde12345";
    str1.erase(0, 2);
    cout << str1 << endl;
    cout << "=========================" << endl;
}

// assign() �� = �������Ը��ߣ�����ѡ���Եĸ�ֵ�ַ�����һ����
void testString_p5()
{
    string str1;
    string s = "12345";
    str1.assign("abcde12345");
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s, 2, 2); // ע��˴�param2����ʼ������param3�ǳ���
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(5, '*');
    cout << str1 << endl;
    cout << "=========================" << endl;
    str1.assign(s.begin()+1, s.end()); // ��������ǰ�պ�
    cout << str1 << endl;

    auto it = str1.begin();
    cout << *it << endl;
    it.operator++();
    cout << *it << endl;
}

// append() �� operator+=�������Ը���
void testString_p6()
{
    string str1 = "abc";
    string temp = "ABCDE";
    str1.append(temp);
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(temp, 2, 3); // ע��˴�param2����ʼ������param3�ǳ��ȶ�����������
    cout << str1 << endl;

    str1 = "abc";
    str1.append("ABCDE", 2, 3); // ע��˴�param2����ʼ������param3�ǳ��ȶ�����������
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append("ABCDE", 2); // ��ע��˴�Ϊǰ2���ַ�
    cout << str1 << endl;
    str1 = "abc";
    str1.append(string("ABCDE"), 2); // ��ע��˴�Ϊ������2��ʼ�����
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(5, 'A'); // ׷��5��A
    cout << str1 << endl;
    cout << "=========================" << endl;

    str1 = "abc";
    str1.append(temp.begin() + 1, temp.end() - 1); // ע��˴�Ϊǰ�պ�, ע����������ܵ�������
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
    str1 += {'*', '%', '$'}; // +=��ʼ���б�����
    cout << str1 << endl;
    cout << "=========================" << endl;
}

// replace()
void testString_p8()
{
    //string& replace(size_t pos, size_t len, const string& str);
    string str1("abcde12345");
    const string temp("uvwxyz");
    str1.replace(2, 3, temp); // ע��˴�param2�ǳ��ȣ�������������������ʼ����+���ȣ�����ǰ�պ�գ�
    cout << str1 << endl;
    cout << "1=========================" << endl;

    //string& replace(iterator i1, iterator i2, const string& str);
    str1 = "abcde12345";
    str1.replace(str1.begin() + 1, str1.begin() + 3, temp); // ע���������ǰ�պ�
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

// find�ຯ��
void testString_p9()
{
    string str("abcde12345abcde12345");
    size_t index = str.find("c"); // û�ҵ�����npos
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

// conmpare() ���ַ���ASCII�Ƚ�
void testString_p11()
{
    string str1("abcde12345");
    string str2("abcde12345");
    string str3("accde12345");
    string str4("aacde12345");
    int ret = str1.compare(str2); // ��ȷ���0
    cout << ret << endl;
    cout << "1=========================" << endl;

    ret = str1.compare(str3);
    cout << ret << endl; // С�ڷ���-1
    cout << "2=========================" << endl;

    ret = str1.compare(str4);
    cout << ret << endl; // С�ڷ���1
    cout << "3=========================" << endl;
}

/*
strcpy��memcpy��Ҫ������3���������
1�����Ƶ����ݲ�ͬ��strcpyֻ�ܸ����ַ�������memcpy���Ը����������ݣ������ַ����顢���͡��ṹ�塢��ȡ�
2�����Ƶķ�����ͬ��strcpy����Ҫָ�����ȣ��������������ַ��Ĵ�������"\0"�Ž������������������memcpy���Ǹ������3�������������Ƶĳ��ȡ�
3����;��ͬ��ͨ���ڸ����ַ���ʱ��strcpy������Ҫ����������������ʱ��һ����memcpy
*/
// copy()
void testString_p12()
{

}

// �����ַ�������
void testString_p165()
{
    string str("abcde12345");
    const char* charPtr1 = str.c_str();
    const char* charPtr2 = str.data();
}


#endif // !STRING_P_HPP