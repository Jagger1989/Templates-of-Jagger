#include "src/Utility/common.h"

#include <chrono>

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
    string str("");
    string temp("abc123");

    std::chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    for (size_t i = 0; i < 999999; i++)
    {
        str.append(temp, 2, 4);
        if (str.size() == str.max_size())
        {
            str = "";
        }
    }
    std::chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "index : " << timeDelta << endl;

    chronoTimeStart = chrono::system_clock::now();
    for (size_t i = 0; i < 999999; i++)
    {
        str.append(temp.begin() + 2, temp.begin() + 5);
        if (str.size() == str.max_size())
        {
            str = "";
        } 
    }
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "iterator : " << timeDelta << endl;
}


