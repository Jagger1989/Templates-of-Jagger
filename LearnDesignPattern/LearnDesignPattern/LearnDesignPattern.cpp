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

class Testttttt
{

};

int get_param()
{
    int i = 100;
    return i;
}

void testMain1()
{
    //int& ri = get_param(); //编译报错，不能使用右值初始化引用，因为改变ri时，右值不能被赋值改变
    const int& ri = get_param(); // 加了const不能修改值，就不存在上面的问题了
    cout << ri << endl;
}

int main()
{

    //placement_new::testPlacementNew2();
    //system("pause");
}

/*
平台:
GNU C++ 是linux平台上的编译工具，.Visual C++是WINDOWS上的编译工具，GNU C++更符合C++规范
库 :
GNU C++使用linux上的API, VC++使用WIN API.
C++语法有微小的差别 :
这里仅仅拿VC6来说明， VC6由于某种原因, 不能很好支持C++新标准, 而GNU C++是完全支持的.
*/