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
��׼����
    ˳������
            vector
            deque
            list
    ��������
            set, multiset
            map, multimap
            unordered_set, unordered_multiset
            unordered_map, unordered_multimap
����������
    stack
    queue
    priority_queue
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

/*
size        ��ǰԪ�ظ���
capacity    ��ǰ�ѷ�����ڴ���������Ԫ�ظ���
max_size    ��������ڴ�ʱ������Ԫ�ظ���

size�ǵ�ǰvector������ʵռ�õĴ�С��Ҳ����������ǰӵ�ж��ٸ�Ԫ�ء�
capacity��ָ�ڷ���reallocǰ����������Ԫ��������Ԥ������ڴ�ռ䡣
��Ȼ�����������Էֱ��Ӧ����������resize()��reserve()��
ʹ��resize()�������ڵĶ����ڴ�ռ����������ڵġ�
ʹ��reserve()����ֻ���޸���capacity��ֵ�������ڵĶ���û����ʵ���ڴ�ռ�(�ռ���"Ұ"��)��
��ʱ�м�ʹ��[]���������������ڵĶ��󣬺ܿ��ܳ�������Խ������⡣
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
            array��Ϊ�˺�C���������������ݶ����õġ���������C���Ե����黹��һЩ����
            C ����û�� begin �� end ��Ա��������Ȼ����ʹ��ȫ�ֵ� begin �� end ��������
            C ����û�� size ��Ա������
            C ������Ϊ�������˻���Ϊ�����ݸ�����һ���������Ǹ����������ܻ�� C ����ĳ��Ⱥͽ���λ�á�
        Vector          �Զ�����
            (1) һ����̬���������(������ռ��ڴ治��ʱ������ִ��: �����¿ռ�-����Ԫ��-�ͷ�ԭ�ռ�);
            (2) ��ɾ��Ԫ��ʱ�������ͷ����ƵĿռ䣬������������������(capacity)�������������Ĵ�С(size);
            (3) ����ɾ������������ִ��Ч�ʲ��ߣ�Խ��������ɾ��ִ��Ч��Խ��;
            (4) ��Ч��������ʵ�������
        Deque           ˫�˶���
            (1) deque(double-ended queue ˫�˶���);
            (2) ���зֶ����顢��������, �ֶ������Ǵ洢���ݵģ����������Ǵ洢ÿ��������׵�ַ;
            (3) �����˲���Ԫ��Ч�ʽϸߣ�
                (�������˲���Ԫ�أ�������˵ķֶ�����δ�����ȿɲ���;������˵ķֶ�����������
                �򴴽��µķֶκ��������ѷֶ�������׵�ַ�洢��deque�����м���)��
                �м����Ԫ��Ч�ʽϵͣ�
        List            ˫������
        Forward-List    ��������
    ����������   Associative Containers
        Set/Multiset    ����� value����key key����value�� Set�����ظ���Multiset���ظ�
        Map/Multimap    
    ��������    Unordered Containers
        Unordered Set/Multiset
        Unordered Map/Multmap
*/


/*
vector              ���������
array               ���������
deque               ���������
list                ˫�������
forward_list        ���������
set                 ˫�������
multiset            ˫�������
map                 ˫�������
multimap            ˫�������
unordered_set       ���������
unordered_map       ���������
unordered_multiset  ���������
unordered_multimap  ���������

// ???
input               ���������
output              ���������
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

void testList2()
{
    vector<int> list(10, 1);
    auto it = list.begin();
    for (; it != list.end(); ++it)
        cout << *it << endl;

    list.insert(it, 19); // �����ᵼ�µ�����ʧЧ���ٴ�ʹ�õ�����it�ᵼ�²���Ԥ����Ϊ
    cout << "=======================" << endl;
    for (; it != list.begin(); --it)
        cout << *it << endl;
    cout << "=======================" << endl;
}

void testAllocator()
{
    // STL�ײ㿪���ڴ淽ʽ��new�ĵײ㣩
    int *p = allocator<int>().allocate(512, (int*)0);
    allocator<int>().deallocate(p, 512);
}

#endif // !CONTAINERS_HPP