#ifndef TYPE_CAST_H
#define TYPE_CAST_H

#include "../Utility/common.h"
using namespace std;

class AA
{
public:

private:
};

class BB
{
public:

private:
};

class C : public AA,  public BB
{
public:

private:
};

void testTypeCast()
{
    // Cǿ������ת��
    double age = 20.3;
    int my_age = int(age);

    // C++ǿ������ת��
    // 1. static_cast ����ת���ͷ�����������, ���Զ�ƫ��
    {
        int my_age2 = static_cast<int>(age);

        int a = 20;
        int* p = &a;
        //double* pa = static_cast<double*>(p); //ֱ��ת�����뱨��,������ͨ��void*����
        void* pp = static_cast<void*>(p);
        double* ppp = static_cast<double*>(pp);

        std::cout << *p << std::endl;
        //std::cout << *pp << std::endl;        //���뱨��,void*����ֱ��ʹ��
        std::cout << *ppp << std::endl;
        //printf("%d\n", *ppp);
    }

    // 2. const_cast ����ת����const -> ��const volatile -> ��volatile
    {
        const int a = 10;
        //int* p = &a;                  // ���뱨��,��constָ��ָ��const��,��������Ϊ�������ͨ����ôp�Ϳ����޸�const a��ֵ��
        int* p1 = (int*)&a;             // ǿ��ȥ��const����
        int* p2 = const_cast<int*>(&a); // ǿ��ȥ��const����, �Զ�������Ҳ����
        std::cout << *p1 << std::endl;
        std::cout << *p2 << std::endl;

        volatile int k = 0; // volatile �ױ���
        //int* q = &k; //���뱨��
        int* q = const_cast<int*>(&k); // ǿ��ȥ��volatile����, �Զ�������Ҳ����
        std::cout << *q << std::endl;
    }

    // 3. reinterpret_cast �ؽ���, 
    {
        int i;
        const char* p = "this is C++!";
        i = reinterpret_cast<int>(p);

        C c;
        printf("%p\r\n", &c);
        printf("%p\r\n", reinterpret_cast<BB*>(&c)); // reinterpret_cast��������ת����BBָ�룬��ַ��ԭ��һ��
        printf("%p\r\n", static_cast<BB*>(&c)); // static_cast�Զ���ַƫ�ƣ���ȷת��ΪBBָ��

    }

    // 4. dynamic_cast ���������͵�ָ������ð�ȫ��ת��Ϊ�����������͵�ָ�������
    {

    }
}

#include <typeinfo>

// typeid()
void testTypeCast2()
{
    AA a;
    std::string name = typeid(a).name();
    cout << name << endl;
}

#endif // !TYPE_CAST_H