#ifndef TEMPLATE_DEQUE_H
#define TEMPLATE_DEQUE_H
#include "../Utility/common.h"

//vector与deque二者容器的区别
//
//（1、deque访问容器元素的效率比vector容器慢很多；
//原因在于deque要跨内存块来访问，而vector只是使用一个内存块，不用跨内存的操作。vector容器相当于一个可以动态分配的数组。
//（2、扩充容器容量的方面deque比vector的效率高很多；
//deque是申请一个小的内存块，然后把新申请的内存块与其它的deque内存块整合起来。
//vector是申请一个比原先更大的新内存块，把原vector里面的数据复制到新的大内存块里面，然后还的销毁原先vector的内存块。所以，在容量扩充方面，deque比vector高效，而且内存利用率也高。
//（3、vector不可以收缩，deque自动收缩；
//vector不支持把容器的容量调小的操作，小于的情况不会有任何操作。而deque因为它是有很多小内存块的组成的，所以有空闲的内存块时，会销毁空闲的内存块，但不会影响deque里面已有的数据。
//
//vector在默认情况下是典型的使用序列的方法，对于deque，当使用插入删除操作的时候是一个更好的选择
//deque比vector增加了两个函数：
//（1、c.push_front(elem) —— 在头部插入一个数据。
//
//（2、c.pop_front() —— 删除头部数据。
//
//deque比vector少了两个函数：
//（1、capacity()—— 返回vector当前的容量。
//
//（2、reserve() —— 给指定vector的大小。

void testDeque()
{

    // 比vector多了前端插入和弹出，内存管理与vector不一样，deque：大块分配内存
    std::deque<int> deq;
    deq.push_front(1);
    deq.pop_front();

}

#endif // !TEMPLATE_DEQUE_H