#include "src/Utility/common.h"
#include <iostream>

#include "src/Template/Template_String.hpp"
#include "src/Template/Template_Functor.h"
#include "src/TemplatePrograming/Template_1.h"
#include "src/STL/containers.hpp"
#include "src/PerformanceTest/test_vector.hpp"
#include "src/Boost/boost_string.hpp"
#include "Temp.hpp"

#include "src/STL/string_p.hpp"
#include "src/Template/placement_new.hpp"
#include "src/Template/override_operator.hpp"
#include "src/Template/type_cast.hpp"

class Testttttt
{
public:
    int x = 1;

    ~Testttttt()
    {
        cout << "Testttttt destructor" << endl;
    }
};

int get_param()
{
    int i = 100;
    return i;
}

Testttttt& testRef2()
{
    Testttttt temp;
    temp.x = 2;
    return temp;
}

Testttttt& testRef()
{
    Testttttt obj = testRef2();
    return obj;
}

void testMain1()
{
    //int x = 0;
    //x = x++;
    //cout << x << endl;

    Testttttt& ttttt = testRef();
    ::Sleep(5000);
    testRef2();
    ::Sleep(5000);
    testRef();
    ::Sleep(5000);
    cout << ttttt.x << endl;


    //int& ri = get_param(); //编译报错，不能使用右值初始化引用，因为改变ri时，右值不能被赋值改变
    //const int& ri = get_param(); // 加了const不能修改值，就不存在上面的问题了
    //cout << ri << endl;
}

int main()
{
    testMain1();
    //placement_new::testPlacementNew2();
    system("pause");
}

/*
平台:
GNU C++ 是linux平台上的编译工具，.Visual C++是WINDOWS上的编译工具，GNU C++更符合C++规范
库 :
GNU C++使用linux上的API, VC++使用WIN API.
C++语法有微小的差别 :
这里仅仅拿VC6来说明， VC6由于某种原因, 不能很好支持C++新标准, 而GNU C++是完全支持的.
*/