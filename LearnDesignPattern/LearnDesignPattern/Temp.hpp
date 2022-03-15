#include "src/Utility/common.h"

#include <chrono>

using namespace std;

class Test123
{
public:
    Test123(int x):x(x){}
    int x = 1;
};

class Temp {
public:
    static const int A = 5;
    //inline static const Test123 MM = Test123(1);

    Temp(int _a) : m_a(_a){}

    void print()
    {
        cout << A + m_a << endl;
        //cout << MM.x << endl;
    }

private:
    int m_a;
};

void testTemp()
{
    Temp(1).print();
}

class Temp2 {
public:
    
};

void testTemp2()
{
    int* p = nullptr;
    ::operator delete(p);

    vector<int> list({1,2,3});
    vector<int>::iterator it = list.begin();
    it.operator++();
    cout << *it << endl;

}

//const Test123 Temp::MM = Test123(1);

