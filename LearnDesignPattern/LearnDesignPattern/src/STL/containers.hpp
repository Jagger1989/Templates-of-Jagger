#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP
#include "../Utility/common.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

/*
OO object-oriented  �������
GP generic programming ���ͱ��

STL���󲿼�(�μ�testSTLContainer())��
    ����  (Containers) �洢����               vi
    ������(Allocators) ����֧�����������ڴ�    Allocator<int>
    �㷨  (Algorithms) ͨ������������������    count_if()
    ������(Iterators)  ����ָ��               begin() end()
    ������(Adapters)                         bind2nd()
    �º���(Functors)                         less<int>()
*/

/*
���Ӷ�
    O(1)        ����ʱ��
    O(n)        ����ʱ��
    O(log2n)    ������ʱ��
    O(n^2)      ƽ��ʱ��
    O(n^3)      ����ʱ��
    O(2^n)      ָ��ʱ��
    O(nlog2n)   �������Լ����η��̳����м�֮��Ϊģʽ
*/

void testSTLContainer()
{
    int ia[6] = { 27, 210, 12, 47, 109, 83 };
    // allocator<int>ָ��ÿ�η���int��С�ڴ棬��дʹ��Ĭ�Ϸ�����
    // ������ia���׵�ַ��β��ַ��Ϊ�������룬��vi��ʼ��Ϊ27, 210, 12, 47, 109, 83
    vector<int, allocator<int> > vi(ia, ia + 6);

    // ����
    ::sort(vi.begin(), vi.end());
    //cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
    // foreach���������κ�����
    for (int i : {1, 2, 3})
    {
        cout << i << endl;
    }
}

/*
����
    ��������    Sequence Containers
        Array           ����
        Vector          �Զ�����
        Deque           ˫�˶���
        List            ˫������
        Forward-List    ��������
    ����������   Associative Containers
        Set/Multiset    ����� value����key key����value�� Set�����ظ���Multiset���ظ�
        Map/Multimap    
    ��������    Unordered Containers
        Unordered Set/Multiset
        Unordered Map/Multmap
*/

#include <list>

void testList()
{
    int arr[] = {3,1,2,3,4,2};
    list<int> list1(arr, arr+3);
    list1.sort();
    //::sort(list1.begin(), list1.end()); // ::sort��֧��list
    for (auto o : list1)
    {
        cout << o << endl;
    }    
}

void testAllocator()
{
    // STL�ײ㿪���ڴ淽ʽ��new�ĵײ㣩
    int *p = allocator<int>().allocate(512, (int*)0);
    allocator<int>().deallocate(p, 512);
}

#endif // !CONTAINERS_HPP