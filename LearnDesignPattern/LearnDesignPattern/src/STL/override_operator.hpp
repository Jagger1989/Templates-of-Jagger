#ifndef OVERRIDE_OPERATOR_HPP
#define OVERRIDE_OPERATOR_HPP

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class CustomVector {
public:
    CustomVector(T _val): m_value(_val){}


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

    // ��д����ת��������
    // �ñ����Ͷ�����������Ͷ���ֵʱ����
    // https://news.68idc.cn/netjishu/cjj/20150714443740.html
    operator int() const
    {
        return int(m_x);
    }

    // ��дoperator new() ���˴���������ʵ����ԭ���operator new����ע��operator new��new operator����һ��������new operator���ҳ����õ�new delete�Ǹ�new
    // new operator�ײ�����ȵ���operator new(�ײ���malloc)�������ڴ棬Ȼ����ù��캯��
    void* operator new(size_t size)
    {
        return malloc(size);
    }

    // ����operator new
    // ���ص�ǰ���ǵ�һ����������λsize_t������������ᱨ��
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

    //obj.operator++();  // ǰ++
    //obj.operator++(0); // ��++
}

#endif