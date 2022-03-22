#ifndef OVERRIDE_OPERATOR_HPP
#define OVERRIDE_OPERATOR_HPP

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class CustomVector {
public:
    CustomVector(int _val): m_value(_val){}


    // 重写++obj
    CustomVector& operator++()
    {
        m_value++;
        return *this;
    }

    // 重写obj++
    CustomVector operator++(int) // 这个int参数是用于区分前++和后++的伪参数,
                                 // C++编辑器可以通过在运算符函数参数表中是否插入关键字int来区分这两种方式
    {
        CustomVector temp = *this;
        ++(*this);
        return temp;
    }

    void print()
    {
        cout << "value = " << m_value << endl;
    }

private:
    T m_value;
};

void testOverrideOperator()
{
    CustomVector<int> obj(1);
    obj.print();
    (obj++).print();
    (++obj).print();

    obj.operator++();  // 前++
    obj.operator++(0); // 后++
}

#endif