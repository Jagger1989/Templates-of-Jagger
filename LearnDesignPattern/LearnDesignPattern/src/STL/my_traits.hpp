#ifndef MY_TRAITS_HPP
#define MY_TRAITS_HPP
#include "../Utility/common.h"

using namespace std;

namespace my_traits {

    struct __true_type {

    };

    struct __false_type {

    };

    void  testTraits(__false_type)
    {
        printf("__false_type\n");
    }

    void  testTraits(__true_type)
    {
        printf("__true_type\n");
    }

    template<typename T>
    class __type_traits {
    public:
        typedef __false_type categoryType;
    };

    template<>
    class __type_traits<int> {
    public:
        typedef __true_type categoryType;
    };

    template<typename T>
    class containers {
    public:
        typedef typename __type_traits<T>::categoryType categoryType;

        void test()
        {
            // 通过__type_traits萃取出categoryType的类型，再通过萃取出的不同类型作为参数来调用相应的重载函数，实现编译期流程空子
            testTraits(categoryType());
        }
    };




}

void testMyTraits()
{
    my_traits::containers<int> obj1;
    obj1.test();
    my_traits::containers<double> obj2;
    obj2.test();
}


#endif // !MY_TRAITS_HPP