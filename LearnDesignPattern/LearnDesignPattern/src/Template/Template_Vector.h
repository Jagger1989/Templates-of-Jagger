#ifndef TEMPLATE_VECTOR_H
#define TEMPLATE_VECTOR_H
#include <algorithm>

#include "../Utility/common.h"


class TestVector
{
public:

private:
};

void testVector()
{
    std::vector<int> list =
    {
        1,2,3,4
    };
    transform(list.begin(), list.end(), list.begin(), [&](int point) {
        return point + 1;
    });
    for (auto it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

#endif // !TEMPLATE_VECTOR_H