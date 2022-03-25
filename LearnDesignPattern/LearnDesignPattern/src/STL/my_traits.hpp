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
            // ͨ��__type_traits��ȡ��categoryType�����ͣ���ͨ����ȡ���Ĳ�ͬ������Ϊ������������Ӧ�����غ�����ʵ�ֱ��������̿���
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