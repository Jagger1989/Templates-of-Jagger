#include "src/Utility/common.h"

using namespace std;

class Temp {
public:
    Temp(int v)
    {
        m_list.push_back(v);
        m_list.push_back(++v);
        m_list.push_back(++v);
    }

    bool operator>(const Temp& tar)
    {
        return m_list[0] > tar.m_list[0];
    }

    int operator[](size_t index)
    {
        return m_list[index];
    }

private:
    vector<int> m_list;
};

class MyFunctor {
public:
    MyFunctor(int x) : m_v(x){}

    void operator()()
    {
        cout << m_v << endl;
    }

private:
    int m_v;
};

template<typename Fun>
void tempppp(Fun func)
{
    func();
}

template <typename T>
T asdfasf(T x)
{
    return x;
}

void testTemp()
{
    MyFunctor mf(10);
    tempppp(mf);
    asdfasf(Temp(1));
}



