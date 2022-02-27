#ifndef STREAM_HPP
#define STREAM_HPP
#include "../Utility/common.h"

#include <iostream>
using namespace std;

void testStream()
{
    char ch[20];
    cout << "ÊäÈë×Ö·û´®" << endl;
    int n = cin.get();
    cout << "n = " << n << endl;
    cin.getline(ch, 20);
    cout << "¸Ã×Ö·û´®ÊÇ" << ch << endl;
    cout << "ÊäÈë×Ö·û´®" << endl;
    cin.getline(ch, 20, '\\');
    cout << "¸Ã×Ö·û´®ÊÇ" << ch << endl;
}

#endif // !STREAM_HPP