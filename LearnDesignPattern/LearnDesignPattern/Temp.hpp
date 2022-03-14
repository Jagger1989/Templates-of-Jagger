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

    void print()
    {
        cout << A << endl;
        //cout << MM.x << endl;
    }
};

void testTemp()
{
    Temp().print();
}

//const Test123 Temp::MM = Test123(1);

