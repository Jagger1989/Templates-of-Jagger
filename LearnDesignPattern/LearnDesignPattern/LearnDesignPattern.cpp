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

// 什么时候用new？可参考：https://blog.csdn.net/ftfy123/article/details/104969485/

class TestBase {
public:
    virtual void testPrint()
    {
        printf("Test TestBase\n");
    }
};

class TestDerived : public TestBase {
public:
    void testPrint()
    {
        printf("Test TestDerived\n");
    }
};

void testOOP()
{
    TestDerived derived;;
    TestBase baseObj = derived;  // 对象被裁切为基类对象
    TestBase* basePtr = &derived;
    TestBase& baseRef = derived;
    baseObj.testPrint();  // 调用基类
    basePtr->testPrint(); // 调用派生类
    baseRef.testPrint();  // 调用派生类

    TestBase* P = new TestDerived();
    P->testPrint();
    P->TestBase::testPrint();
}

#include <queue>
void main()
{
    testOOP();
    //placement_new::testPlacementNew2();
    std::deque<int> deq{ 3, 1, 4, 1, 5 };
    system("pause");

}

/*
平台:
GNU C++ 是linux平台上的编译工具，.Visual C++是WINDOWS上的编译工具，GNU C++更符合C++规范
GCC——GNU Compiler Collectino GNU编译器套件，包括C、C++、Java等语言
库 :
GNU C++使用linux上的API, VC++使用WIN API.
C++语法有微小的差别 :
VC6由于某种原因, 不能很好支持C++新标准, 而GNU C++是完全支持的.
*/