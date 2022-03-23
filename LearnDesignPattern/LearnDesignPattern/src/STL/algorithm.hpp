#ifndef STL_ALGORITHM_HPP
#define STL_ALGORITHM_HPP
#include "../Utility/common.h"

using namespace std;

template<typename Container>
void printContainer(const Container& _concainer)
{
    cout << "===================================" << endl;
    for (auto e : _concainer)
        cout << e << " ";
    cout << endl;
    cout << "===================================" << endl;
}

template<typename T>
void printValue(const T& _v)
{
    cout << "===================================" << endl;
    cout << _v << endl;
    cout << "===================================" << endl;
}

void testSTLAlgorithm()
{
    const size_t length = 10;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> list;
    list.reserve(length);
    list.insert(list.begin(), arr, arr + 10);
    printContainer(list);

    // advance()
    auto it = list.begin();
    printValue(*it);
    advance(it, 5);
    printValue(*it);
}

#endif // !STL_ALGORITHM_HPP