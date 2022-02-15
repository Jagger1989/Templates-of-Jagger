#ifndef TEMPLATE_FUNCTOR_H
#define TEMPLATE_FUNCTOR_H

#include "../Utility/common.h"
#include <algorithm>
// 仿函数
class Func {
public:
    explicit Func(const string& str) : ss(str) {}

    void operator() (const string& str) const {
        cout << str << ' ' << ss << endl;
    }

private:
    const std::string ss;
};

// 可传仿函数的函数
template<class _T>
void testffff(_T func)
{
    func("Hello");
}

void testFunctor1()
{
    Func myFunc("world!");
    myFunc("Hello");

    Func("testFunctor1");
    testffff(Func("testFunctor1"));
}

// 应用场景
// 统计长度小于设定值的字符串个数, count_if传入的函数无法传入长度
// 只能用全局变量，这样不规范，不优雅，此时可使用仿函数实现

int g_maxLength;
std::vector<std::string> strlist =
{
    "asdfasdf",
    "asdfasdf",
    "asdfasdf"
};

bool LengthIsLessThan(const std::string& str)
{
    return str.length() < g_maxLength;
}

void testFunctor2()
{
    // count_if->#include <algorithm>
    g_maxLength = 10;
    int ret = count_if(strlist.begin(), strlist.end(), LengthIsLessThan);
    std::cout << "testFunctor2 = " << ret << endl;
}

// 用仿函数实现
// 用成员变量将参数传入
class Functor
{
public:
    Functor(int maxLength):m_maxLength(maxLength) {}

    bool operator()(const std::string& str) const
    {
        return str.length() < m_maxLength;
    }
private:
    int m_maxLength;
};

void testFunctor3()
{
    int ret = count_if(strlist.begin(), strlist.end(), Functor(10));
    std::cout << "testFunctor3 = " << ret << endl;
}



#endif // !TEMPLATE_FUNCTOR_H