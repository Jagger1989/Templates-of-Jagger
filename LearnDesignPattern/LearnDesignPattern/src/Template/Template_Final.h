#ifndef TEMPLATE_FINAL_H
#define TEMPLATE_FINAL_H


// C++11的关键字final有两个用途。第一，它阻止了从类继承；第二，阻止一个虚函数的重载。

class TestFinal final
{
public:

private:
};

// final将类声明为不可继承，以下代码编译报错
//class TestFinal2 : public TestFinal
//{
//
//};

class TestFinal3 {
public:
    virtual void test() final
    {
        printf("abcd\n");
    }

};

class TestFinal4 : public TestFinal3
{
    // final将函数声明为不可重写，以下代码编译报错
    //void test() {}
};

// 重写与覆盖的区别
class TestFinal5
{
public:
    virtual void test1() { printf("final5 test1\r\n"); }
    void test2() { printf("final5 test2\r\n"); }
};

class TestFinal6 : public TestFinal5
{
public:
    // 重写
    void test1() override { printf("final6 test1\r\n"); }
    // 覆盖
    void test2() { printf("final6 test2\r\n"); }
};

void testFinal()
{
    TestFinal5* ptr = new TestFinal6;
    ptr->test1(); // 调用派生类重写的函数      打印 final6 test1
    ptr->test2(); // 基类指针所以调用基类函数  打印 final5 test2
    delete ptr;
    ptr = nullptr;
}


#endif // !TEMPLATE_FINAL_H