#ifndef PLACEMENT_NEW_HPP
#define PLACEMENT_NEW_HPP

namespace placement_new {
    using namespace std;
    class A
    {
    public:
        void print()
        {
            cout << "hello world" << endl;
        }

        ~A() {}
    };

    /*
        һ����˵��ʹ��new����ռ�ʱ���Ǵ�ϵͳ�ġ��ѡ���heap���з���ռ䡣�������õĿռ��λ���Ǹ��ݵ�ʱ���ڴ��ʵ��ʹ����������ġ�
        ���ǣ���ĳЩ��������£�������Ҫ���ѷ�����ض��ڴ洴�������������ν�ġ���λ����new����placement new��������
        ��λ����new�������﷨��ʽ��ͬ����ͨ��new���������磬һ�㶼���������A* p=new A;����ռ䣬����λ����new������ʹ���������
        A* p=new (ptr)A;����ռ䣬����ptr���ǳ���Աָ�����ڴ��׵�ַ��
    */

    void testPlacementNew()
    {
        A* ptr1 = new A; // ����size���ֽڵĴ洢�ռ䣬�����������ͽ����ڴ���롣����ɹ�������һ���ǿյ�ָ��ָ���׵�ַ��ʧ���׳�bad_alloc�쳣
        A* ptr2 = new (std::nothrow)A; // �ڷ���ʧ��ʱ���׳��쳣��������һ��NULLָ��
        A* ptr3 = nullptr;
        new (ptr3)A(); // ��ָ��ptr3��ָ�����ú��ʵĹ��캯��������ʵ��ptr3
        ptr3->print();
    }

    void testPlacementNew2()
    {
        char* p = new char[10 * sizeof(A)];
        A* p2 = new (p)A;
        if ((int)p2 == (int)p)
        {
            cout << "p == p2" << endl;
        }
        // ���������Ϊ�˸��õ����壬��Ϊp2��û�з����ڴ棬
        // delete p2���岻����p�ֲ���A�������Ե�������Ҳ������
        // ����ʹ��p�ͷ��ڴ棬p2��������
        p2->~A();
        delete[] p;
    }

    void test()
    {
        while (true)
        {
            // ���ᵼ���ڴ�й¶����Ϊplancement new����������ڴ棬ʹ�õ���ԭ���ǿ��ڴ棬��ԭָ����ָλ�ù������
            A* p = new A;
            new (p)A();
            delete p;
            p = nullptr;
        }
    }
}

#endif // !PLACEMENT_NEW_HPP