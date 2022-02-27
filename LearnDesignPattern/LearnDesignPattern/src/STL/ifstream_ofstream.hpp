#ifndef IFSTREAM_AND_OFSTREAM_HPP
#define IFSTREAM_AND_OFSTREAM_HPP
#include "../Utility/common.h"

using namespace std;

#include <fstream>

/*
ifstream 输入流
ofstream 输出流
*/

void test_ifstream()
{
    // 直接打开文件
    ifstream in1("bin\\test.txt", ios::in);

    in1.close();

    // 使用open打开
    ifstream in2;
    in2.open("bin\\test.txt", ios::in);

    in2.close();


}

void test_ofstream()
{
    ofstream out1("bin\\test.tex", ios::out);

    out1.close();
}

#endif // !IFSTREAM_AND_OFSTREAM_HPP