#ifndef LIST_P_HPP
#define LIST_P_HPP
#include "../Utility/common.h"

#include <xmemory0>

using namespace std;

namespace my_list {


    template<typename _Tp>
    class _list_node_base {
    public:
        _list_node_base* _M_next;
        _list_node_base* _M_prev;
    };

    template<typename _Tp>
    class _List_node {
    public:
        _Tp _M_data;
    };

    template<typename _Alloc_types>
    class _List_alloc {
        // ������
    };

    template<typename _Tp, typename _A>
    class _List_impl : public _List_alloc<_A> {
    public:
        _list_node_base<_Tp> _M_node;
    };

    template<typename _Tp, typename _A>
    class _List_base {
    public:
        _List_impl<_Tp, _A> _M_impl;
    };

    template<typename T>
    class __list_iterator
    {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;

        typedef __list_iterator<T> self;

        // ���������е�5��typedef
        typedef bidirectional_iterator_tag iterator_category; // ���������ͣ�bidirectional_iterator_tag->˫�������
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type;

        typedef _list_node_base<T>* link_type;

        link_type node;

        reference operator*() const
        {
            return (*node)._M_data;
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        self& operator++()
        {
            node = (link_type)((*node).next);
            return *this;
        }

        self operator++(int)
        {
            self temp = *this; // ע�����ﲢû�е���operator*()���ǵ���self�Ŀ������콫*this����������Ϊ����
                               // ���������Ϊthis��ָ�룬��������operator*()��Ҫ�ö��������õ�/
                               // ���Բ�û�е���operater*()
            ++*this;
            return temp;
        }

    };

    template<typename  T, typename Alloc = allocator<T>>
    class list : public _List_base<T, Alloc> {
    public:
        typedef __list_iterator<T> iterator;

    };


}

void testListP()
{

}

#endif // !LIST_P_HPP