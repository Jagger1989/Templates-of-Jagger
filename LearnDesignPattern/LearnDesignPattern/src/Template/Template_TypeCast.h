#ifndef TYPE_CAST_H
#define TYPE_CAST_H

#include "../Utility/common.h"

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
    C() = default;

    C(int x) : m_value(x)
    {

    }

    // 重写类型转换运算符
    operator int() const
    {
        printf("Called int type cast\n");
        printf("m_value ======= %d\n", m_value);
        return m_value;
    }

    operator double() const
    {
        return 0.5f;
    }

    void printValue()
    {
        printf("Called double type cast\n");
        printf("m_value = %d\n", m_value);
    }

private:
    int m_value = 0;
};

void testTypeCast()
{
    // C强制类型转换
    double age = 20.3;
    int my_age = int(age);

    // C++强制类型转换
    // 1. static_cast 用于转换低风险数据类型, 有自动偏移
    {
        int my_age2 = static_cast<int>(age);

        int a = 20;
        int* p = &a;
        //double* pa = static_cast<double*>(p); //直接转换编译报错,但可以通过void*过度
        void* pp = static_cast<void*>(p);
        double* ppp = static_cast<double*>(pp);

        std::cout << *p << std::endl;
        //std::cout << *pp << std::endl;        //编译报错,void*不能直接使用
        std::cout << *ppp << std::endl;
        //printf("%d\n", *ppp);
    }

    // 2. const_cast 常量转换，const -> 非const volatile -> 非volatile
    {
        const int a = 10;
        //int* p = &a;                  // 编译报错,非const指针指向const了,可以理解为如果编译通过那么p就可以修改const a的值了
        int* p1 = (int*)&a;             // 强制去除const属性
        int* p2 = const_cast<int*>(&a); // 强制去除const属性, 自定义类型也可以
        std::cout << *p1 << std::endl;
        std::cout << *p2 << std::endl;

        volatile int k = 0; // volatile 易变量
        //int* q = &k; //编译报错
        int* q = const_cast<int*>(&k); // 强制去除volatile属性, 自定义类型也可以
        std::cout << *q << std::endl;
    }

    // 3. reinterpret_cast 重解释, 
    {
        int i;
        const char* p = "this is C++!";
        i = reinterpret_cast<int>(p);

        C c;
        printf("%p\r\n", &c);
        printf("%p\r\n", reinterpret_cast<BB*>(&c)); // reinterpret_cast不能真正转换成BB指针，地址和原来一样
        printf("%p\r\n", static_cast<BB*>(&c)); // static_cast自动地址偏移，正确转换为BB指针

    }

    // 4. dynamic_cast 向下转换时使用，有类型检查
    {
        
    }

    // 5. 重写自动类型转换
    C cc(10);
    cc.printValue();
    int x = cc;
    double y = cc;
    printf("x = %d\n", x);
    printf("y = %.2f\n", y);
}

#endif // !TYPE_CAST_H