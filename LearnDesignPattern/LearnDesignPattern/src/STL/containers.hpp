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
GP generic paradigm ���ͱ��

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

#endif // !CONTAINERS_HPP