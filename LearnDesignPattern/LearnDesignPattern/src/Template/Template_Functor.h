#ifndef TEMPLATE_FUNCTOR_H
#define TEMPLATE_FUNCTOR_H

#include "../Utility/common.h"
#include <algorithm>
// �º���
class Func {
public:
    explicit Func(const string& str) : ss(str) {}

    void operator() (const string& str) const {
        cout << str << ' ' << ss << endl;
    }

private:
    const std::string ss;
};

// �ɴ��º����ĺ���
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

// Ӧ�ó���
// ͳ�Ƴ���С���趨ֵ���ַ�������, count_if����ĺ����޷����볤��
// ֻ����ȫ�ֱ������������淶�������ţ���ʱ��ʹ�÷º���ʵ��

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

// �÷º���ʵ��
// �ó�Ա��������������
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