#ifndef OVERRIDE_OPERATOR_HPP
#define OVERRIDE_OPERATOR_HPP

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class CustomVector {
public:
    CustomVector(int _val): m_value(_val){}


    // ��д++obj
    CustomVector& operator++()
    {
        m_value++;
        return *this;
    }

    // ��дobj++
    CustomVector operator++(int) // ���int��������������ǰ++�ͺ�++��α����,
                                 // C++�༭������ͨ����������������������Ƿ����ؼ���int�����������ַ�ʽ
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

    obj.operator++();  // ǰ++
    obj.operator++(0); // ��++
}

#endif