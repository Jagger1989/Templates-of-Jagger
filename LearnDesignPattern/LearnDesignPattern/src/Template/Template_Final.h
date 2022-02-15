#ifndef TEMPLATE_FINAL_H
#define TEMPLATE_FINAL_H


// C++11�Ĺؼ���final��������;����һ������ֹ�˴���̳У��ڶ�����ֹһ���麯�������ء�

class TestFinal final
{
public:

private:
};

// final��������Ϊ���ɼ̳У����´�����뱨��
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
    // final����������Ϊ������д�����´�����뱨��
    //void test() {}
};

// ��д�븲�ǵ�����
class TestFinal5
{
public:
    virtual void test1() { printf("final5 test1\r\n"); }
    void test2() { printf("final5 test2\r\n"); }
};

class TestFinal6 : public TestFinal5
{
public:
    // ��д
    void test1() override { printf("final6 test1\r\n"); }
    // ����
    void test2() { printf("final6 test2\r\n"); }
};

void testFinal()
{
    TestFinal5* ptr = new TestFinal6;
    ptr->test1(); // ������������д�ĺ���      ��ӡ final6 test1
    ptr->test2(); // ����ָ�����Ե��û��ຯ��  ��ӡ final5 test2
    delete ptr;
    ptr = nullptr;
}


#endif // !TEMPLATE_FINAL_H