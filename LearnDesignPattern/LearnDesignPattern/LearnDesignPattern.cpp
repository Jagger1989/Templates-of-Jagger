#include "src/Utility/common.h"
#include <iostream>

#include "src/Template//Template_LLA_Calculate.h"
#include "src/Template//Template_TODO.h"
#include "src/Template//Template_Move.hpp"
#include "src/Template//Template_String.hpp"
#include "src/Template/Template_TypeCast.h"

#define MAX(a, b) { a > b ? a : b }

struct Test000001
{
    int object;
    void function(int) {}
};

int main()
{
    //testMove();
    //testTypeCast();


    //Test000001 test;
    //Test000001* ptr = &test;
    //int Test000001::* po = &Test000001::object;
    //test.*po;
    //ptr->*po;
    //void(Test000001::*pf)(int) = &Test000001::function;
    //(test.*pf)(0);
    //(ptr->*pf)(0);


    //int ret = MAX(1, 2);
    //printf("ret = %d\n", ret);

    testTypeCast2();

    system("pause");
}
