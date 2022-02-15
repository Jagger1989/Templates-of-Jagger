#ifndef TEMPLATE_TODO_H
#define TEMPLATE_TODO_H

#include "../Utility/common.h"

enum class MyEnum :int {
    first,
    second
};

void testTODO()
{
    MyEnum x = MyEnum::first;

    //int y = x + 1; // ���뱨��

    // <std::underlying_type<[enum type]>::type>([enum value]) ���ڻ�ȡenum�ֶε�ԭʼ����ֵ
    int y = static_cast<std::underlying_type<MyEnum>::type>(x) + 1;
    int z = static_cast<std::underlying_type<MyEnum>::type>(MyEnum::second) + 1;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

class TestTODO
{
public:
    TestTODO(int _x) {}
};

void testTODO2()
{
    TestTODO TestTODO1(0);
    TestTODO TestTODO2 = TestTODO1;
    TestTODO TestTODO3{ 0 };
}

#endif // !TEMPLATE_TODO_H