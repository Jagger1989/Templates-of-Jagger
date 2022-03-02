#ifndef SSTREAM_P_HPP
#define SSTREAM_P_HPP
#include "../Utility/common.h"

#include <sstream>
using namespace std;

int str_to_int(string str)
{
    int n = 0;
    stringstream os;
    os << str;
    os >> n;
    return n;
}

string int_to_str(int n)
{
    string s;
    stringstream os;
    os << n;
    os >> s;
    return s;
}

void testSstream_p1()
{
    
}

#endif // !SSTREAM_P_HPP