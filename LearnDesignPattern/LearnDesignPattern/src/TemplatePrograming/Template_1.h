#ifndef TEMPLATE_1_H
#define TEMPLATE_1_H

#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <boost/algorithm/algorithm.hpp>

// ԭ��ģ�壬������
// typename T2 = std::vector<T1>Ĭ��ģ��ʵ��
template<typename T1, typename T2 = std::vector<T1> > // ���������ļ����ű����пո񣬷�����ܻ���>>������������
class MyClass
{
public:
    int tttt();

private:
    T1 num1 = 0;
    T2 num2;
};

//��MyClass�����ػ�
template<> class MyClass<float, float>
{
public:
    int tttt()
    {
        return 0;
    }
};

//��MyClass����ƫ�ػ�
template<typename T1>
class MyClass< T1, int>
{
public:
    int tttt();
};

//template<typename T>
//class MyClass< T, T>
//{
//public:
//	int tttt();
//};

template<typename T1, typename T2>
int MyClass<T1, T2>::tttt()
{
    return 1;
}

template<typename T1>
int MyClass<T1, int>::tttt()
{
    return 0;
}

//template<typename T>
template<class T>
// class��typename��һ���ģ���������struct
inline T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

int testTemplate1()
{
    MyClass<int, int> obj; // ��ԭ��ģ����ػ���MyClass<T1, int>��ƥ�������ػ��ģ���������������ػ���ģ�������뱨��
    std::cout << obj.tttt() << std::endl;

    MyClass<int> obj2; //ʹ����Ĭ��ʵ��
    return 0;
}

#endif // TEMPLATE_1_H