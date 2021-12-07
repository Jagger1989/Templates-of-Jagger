
#include <iostream>
#include "./src/DesignPattern/Pattern_Decoration.h"
#include "src/DesignPattern/Pattern_Singleton.h"
#include "src/DesignPattern/Pattern_Visitor.h"
//#include "src/Pattern_Bridge.h"
#include "src/DesignPattern/Pattern_Factory.h"
#include "src/Template/Template_1.h"

namespace test
{
    class A {

    };

    class B {

    };

    class C : public A, public B
    {

    };
}

int main()
{
    std::shared_ptr<test::A> ptr = std::make_shared<test::A>();
    std::shared_ptr<test::B> ptr2 = std::make_shared<test::B>();

    ptr = ptr2;

    system("pause");
}
