#ifndef STL_VECTOR_HPP
#define STL_VECTOR_HPP
#include "../Utility/common.h"

#include <vector>
#include <algorithm>
using namespace std;

void test_stl_vector1()
{
    std::vector<string> list(10, "abc");
    for (auto it = list.begin(); it != list.end(); it++)
    {
        if (1)
        {
            it = list.erase(it); // 注意这里！！！！！it需要指向下一个
        }
    }
}


#endif // !STL_VECTOR_HPP