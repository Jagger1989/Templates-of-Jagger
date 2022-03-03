#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP
#include "../Utility/common.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

/*
OO object-oriented  面向对象
GP generic programming 泛型编程

STL六大部件(参见testSTLContainer())：
    容器  (Containers) 存储数据               vi
    分配器(Allocators) 用于支持容器分配内存    Allocator<int>
    算法  (Algorithms) 通过迭代器来操作容器    count_if()
    迭代器(Iterators)  泛化指针               begin() end()
    适配器(Adapters)                         bind2nd()
    仿函数(Functors)                         less<int>()
*/

/*
标准容器
    顺序容器
            vector
            deque
            list
    关联容器
            set, multiset
            map, multimap
            unordered_set, unordered_multiset
            unordered_map, unordered_multimap
容器适配器
    stack
    queue
    priority_queue
*/

/*
复杂度
    O(1)        常数时间
    O(n)        线性时间
    O(log2n)    次线性时间
    O(n^2)      平方时间
    O(n^3)      立方时间
    O(2^n)      指数时间
    O(nlog2n)   介于线性及二次方程长的中间之行为模式
*/

/*
size        当前元素个数
capacity    当前已分配的内存最大可容纳元素个数
max_size    分配最大内存时可容纳元素个数

size是当前vector容器真实占用的大小，也就是容器当前拥有多少个元素。
capacity是指在发生realloc前能允许的最大元素数，即预分配的内存空间。
当然，这两个属性分别对应两个方法：resize()和reserve()。
使用resize()，容器内的对象内存空间是真正存在的。
使用reserve()仅仅只是修改了capacity的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
此时切记使用[]操作符访问容器内的对象，很可能出现数组越界的问题。
*/

void testSTLContainer()
{
    int ia[6] = { 27, 210, 12, 47, 109, 83 };
    // allocator<int>指明每次分配int大小内存，不写使用默认分配器
    // 将数组ia的首地址和尾地址作为参数传入，将vi初始化为27, 210, 12, 47, 109, 83
    vector<int, allocator<int> > vi(ia, ia + 6);

    // 排序
    ::sort(vi.begin(), vi.end());
    //cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
    // foreach可以用于任何容器
    for (int i : {1, 2, 3})
    {
        cout << i << endl;
    }
}

/*
容器
    有序容器    Sequence Containers
        Array           定长
        Vector          自动扩充
        Deque           双端队列
        List            双向链表
        Forward-List    单向链表
    关联型容器   Associative Containers
        Set/Multiset    红黑树 value就是key key就是value， Set不可重复，Multiset可重复
        Map/Multimap    
    无序容器    Unordered Containers
        Unordered Set/Multiset
        Unordered Map/Multmap
*/

#include <list>

void testList()
{
    int arr[] = {3,1,2,3,4,2};
    list<int> list1(arr, arr+3);
    list1.sort();
    //::sort(list1.begin(), list1.end()); // ::sort不支持list
    for (auto o : list1)
    {
        cout << o << endl;
    }    
}

void testAllocator()
{
    // STL底层开辟内存方式（new的底层）
    int *p = allocator<int>().allocate(512, (int*)0);
    allocator<int>().deallocate(p, 512);
}

#endif // !CONTAINERS_HPP