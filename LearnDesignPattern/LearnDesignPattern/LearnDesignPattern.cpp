#include "src/Utility/common.h"
#include <iostream>

#include "src/PerformanceTest/test_vector.hpp"
#include "src/Boost/boost_string.hpp"
#include "Temp.hpp"

// Template/
#include "src/Template/placement_new.hpp"
#include "src/Template/type_cast.hpp"
#include "src/Template/Template_Move.hpp"
#include "src/Template/Template_Functor.h"
#include "src/TemplatePrograming/Template_1.h"

// STL/
#include "src/STL/string_p.hpp"
#include "src/STL/list_p.hpp"
#include "src/STL/containers.hpp"
#include "src/STL/algorithm.hpp"
#include "src/STL/override_operator.hpp"
#include "src/STL/my_traits.hpp"

#include <typeinfo>

template<typename T>
void func(T iter)
{
    std::string name = typeid(iter).name();
    cout << name << endl;

    int x = 1;
    int &b = x;
}
#include <set> 
#include <typeinfo>
#include <chrono>

// 不适用new，普通创建一个对象，例如 A a;那么这个对象是存放在堆上还是栈上？
// 如果是在函数内部，那么是放在栈上，如果作为某个类的成员，那么就看这个类对象是new还是直接创建，以此类推
// 可参考文章：https://www.cnblogs.com/liushui-sky/p/5741646.html

int testMain2()
{
    char buf[10];
    multiset<string> my_set;
    int size = 100000000;
    std::chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    for (int i = 0; i < size; i++)
    {
        snprintf(buf, 10, "%d", rand()); // rand() 0~32767
        my_set.insert(buf);
    }
    std::chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    int timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;
    string target = "12345";

    chronoTimeStart = chrono::system_clock::now();
    find(my_set.begin(), my_set.end(), target);
    chronoTimeEnd = chrono::system_clock::now();

    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;

    chronoTimeStart = chrono::system_clock::now();
    auto it = my_set.find(target);
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    if (it != my_set.end())
    {
        cout << "founded" << endl;
    }
    cout << timeDelta << endl;
    //testOverrideOperator();
}

//#include <allocators>

const int MAX = 3;

void main()
{
    placement_new::testPlacementNew2();

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