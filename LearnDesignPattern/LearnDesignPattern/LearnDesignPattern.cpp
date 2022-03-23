#include "src/Utility/common.h"
#include <iostream>

#include "src/PerformanceTest/test_vector.hpp"
#include "src/Boost/boost_string.hpp"
#include "Temp.hpp"

// Template/
#include "src/Template/placement_new.hpp"
#include "src/Template/override_operator.hpp"
#include "src/Template/type_cast.hpp"
#include "src/Template/Template_String.hpp"
#include "src/Template/Template_Functor.h"
#include "src/TemplatePrograming/Template_1.h"

// STL/
#include "src/STL/string_p.hpp"
#include "src/STL/list_p.hpp"
#include "src/STL/containers.hpp"
#include "src/STL/algorithm.hpp"

#include <typeinfo>

template<typename T>
void func(T iter)
{
    std::string name = typeid(iter).name();
    cout << name << endl;
}

int main()
{
    testOverrideOperator();
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