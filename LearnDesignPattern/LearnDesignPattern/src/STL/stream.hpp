#ifndef STREAM_HPP
#define STREAM_HPP
#include "../Utility/common.h"

#include <iostream>
using namespace std;

void testStream()
{
    char ch[20];
    cout << "�����ַ���" << endl;
    int n = cin.get();
    cout << "n = " << n << endl;
    cin.getline(ch, 20);
    cout << "���ַ�����" << ch << endl;
    cout << "�����ַ���" << endl;
    cin.getline(ch, 20, '\\');
    cout << "���ַ�����" << ch << endl;
}

#endif // !STREAM_HPP