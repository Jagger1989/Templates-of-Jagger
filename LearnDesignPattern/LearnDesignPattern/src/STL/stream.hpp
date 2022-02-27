#ifndef STREAM_HPP
#define STREAM_HPP
#include "../Utility/common.h"

#include <iostream>
using namespace std;

void testStream()
{
    char ch[20];
    cout << "输入字符串" << endl;
    int n = cin.get();
    cout << "n = " << n << endl;
    cin.getline(ch, 20);
    cout << "该字符串是" << ch << endl;
    cout << "输入字符串" << endl;
    cin.getline(ch, 20, '\\');
    cout << "该字符串是" << ch << endl;

    cerr << "fata" << endl; // 无缓冲，有一条输出一条
    clog << "test clog" << endl;
}

#endif // !STREAM_HPP