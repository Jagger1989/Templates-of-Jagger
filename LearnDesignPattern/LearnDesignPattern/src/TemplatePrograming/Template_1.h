#ifndef TEMPLATE_1_H
#define TEMPLATE_1_H

#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <boost/algorithm/algorithm.hpp>

// 原型模板，必须有
// typename T2 = std::vector<T1>默认模板实参
template<typename T1, typename T2 = std::vector<T1> > // 这里连续的尖括号必须有空格，否则可能会与>>流操作符混淆
class MyClass
{
public:
    int tttt();

private:
    T1 num1 = 0;
    T2 num2;
};

//对MyClass进行特化
template<> class MyClass<float, float>
{
public:
    int tttt()
    {
        return 0;
    }
};

//对MyClass进行偏特化
template<typename T1>
class MyClass< T1, int>
{
public:
    int tttt();
};

//template<typename T>
//class MyClass< T, T>
//{
//public:
//	int tttt();
//};

template<typename T1, typename T2>
int MyClass<T1, T2>::tttt()
{
    return 1;
}

template<typename T1>
int MyClass<T1, int>::tttt()
{
    return 0;
}

//template<typename T>
template<class T>
// class和typename是一样的，不可以用struct
inline T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

int testTemplate1()
{
    MyClass<int, int> obj; // 与原型模板和特化的MyClass<T1, int>都匹配优先特化的，但是如果满足多个特化的模板则会编译报错
    std::cout << obj.tttt() << std::endl;

    MyClass<int> obj2; //使用了默认实参
    return 0;
}

#endif // TEMPLATE_1_H