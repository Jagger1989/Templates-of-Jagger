#ifndef TEMPLATE_STRING_H
#define TEMPLATE_STRING_H
#include "../Utility/common.h"

#include <boost/lexical_cast.hpp>

void testString()
{
    double x = 1.1111111111111111111111f;

    std::string xS = boost::lexical_cast<std::string>(x); // 没问题
    std::string xT = std::to_string(x); // 丢精度，应该是float

    std::cout << xS << std::endl;
    std::cout << xT << std::endl;

    std::string str = "2.22212312312312312312";
    double strD = boost::lexical_cast<double>(str);
    std::cout << strD << std::endl;

}

#endif // !TEMPLATE_STRING_H