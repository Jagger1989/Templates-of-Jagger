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

    void operator()(int y)
    {
        cout << m_v << endl << y << endl;
        cout << m_v + y << endl;
    }

private:
    const int m_v;
};

template<typename Fun>
void tempppp(Fun func)
{
    func(1);
}

template <typename T>
T asdfasf(T x)
{
    return x;
}
#include <xmemory>
void testTemp()
{
    //const MyFunctor mf(10);
    //tempppp(mf);
    //asdfasf(Temp(1));
    //int arr[] = { 1,3,4 };
    //int x = end(arr) - begin(arr);
    //cout << x << endl;
    //vector<int> list = {12,313,14,1};
    //list.shrink_to_fit();
    //cout << list.capacity() << endl;
    list<int> list2;
    cout << sizeof list2 << endl;
}


