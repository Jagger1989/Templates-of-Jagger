#ifndef OVERRIDE_OPERATOR_HPP
#define OVERRIDE_OPERATOR_HPP

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class CustomVector {
public:
    CustomVector(T _val): m_value(_val){}


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

    // 重写类型转换操作符
    // 用本类型对象给其他类型对象赋值时调用
    // https://news.68idc.cn/netjishu/cjj/20150714443740.html
    operator int() const
    {
        return int(m_x);
    }

    // 重写operator new() （此处函数体其实就是原版的operator new），注意operator new和new operator不是一个东西，new operator是我常常用的new delete那个new
    // new operator底层会首先调用operator new(底层是malloc)来分配内存，然后调用构造函数
    void* operator new(size_t size)
    {
        return malloc(size);
    }

    // 重载operator new
    // 重载的前提是第一个参数必须位size_t，否则编译器会报错
    void* operator new(size_t size, void* start)
    {
        return start;
    }

    void print()
    {
        cout << "value = " << m_value << endl;
    }

private:
    T m_value;
    int m_x = 11;
};

void testOverrideOperator()
{
    int x = CustomVector<int>(1);
    printf("%d", x);
    //CustomVector<int> obj(1);
    //obj.print();
    //(obj++).print();
    //(++obj).print();

    //obj.operator++();  // 前++
    //obj.operator++(0); // 后++
}

#endif