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
        一般来说，使用new申请空间时，是从系统的“堆”（heap）中分配空间。申请所得的空间的位置是根据当时的内存的实际使用情况决定的。
        但是，在某些特殊情况下，可能需要在已分配的特定内存创建对象，这就是所谓的“定位放置new”（placement new）操作。
        定位放置new操作的语法形式不同于普通的new操作。例如，一般都用如下语句A* p=new A;申请空间，而定位放置new操作则使用如下语句
        A* p=new (ptr)A;申请空间，其中ptr就是程序员指定的内存首地址。
    */

    void testPlacementNew()
    {
        A* ptr1 = new A; // 分配size个字节的存储空间，并将对象类型进行内存对齐。如果成功，返回一个非空的指针指向首地址。失败抛出bad_alloc异常
        A* ptr2 = new (std::nothrow)A; // 在分配失败时不抛出异常，它返回一个NULL指针
        A* ptr3 = nullptr;
        new (ptr3)A(); // 在指针ptr3所指处调用合适的构造函数，返回实参ptr3
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
        // 理解这里是为了更好的语义，因为p2并没有分配内存，
        // delete p2语义不合理，p又不是A类型所以调用析构也不合理
        // 最终使用p释放内存，p2调用析构
        p2->~A();
        delete[] p;
    }

    void test()
    {
        while (true)
        {
            // 不会导致内存泄露，因为plancement new并不会分配内存，使用的是原来那块内存，在原指针所指位置构造对象
            A* p = new A;
            new (p)A();
            delete p;
            p = nullptr;
        }
    }
}

#endif // !PLACEMENT_NEW_HPP