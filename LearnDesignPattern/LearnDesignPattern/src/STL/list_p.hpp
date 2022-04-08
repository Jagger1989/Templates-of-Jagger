#ifndef LIST_P_HPP
#define LIST_P_HPP
#include "../Utility/common.h"

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
        // 分配器
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

        // 迭代器必有的5个typedef
        typedef bidirectional_iterator_tag iterator_category; // 迭代器类型，bidirectional_iterator_tag->双向迭代器
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ptrdiff_t difference_type; // ???
                                           // 用来表示两个迭代器之间的距离，因此它也可以用来表示一个容器的最大容量
                                           // 因为对于连续空间的容器而言，头尾之间的距离就是其最大容量。

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
            self temp = *this; // 注意这里并没有调用operator*()，是调用self的拷贝构造将*this即本对象作为参数
                               // 可以理解因为this是指针，如果想调用operator*()是要用对象来调用的/
                               // 所以并没有调用operater*()
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