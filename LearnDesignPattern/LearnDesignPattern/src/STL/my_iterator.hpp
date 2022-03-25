#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP
#include "../Utility/common.h"

using namespace std;

template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template<class Iterator>
struct iterator_traits<Iterator*>
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

//template<class Iterator>
//struct iterator_traits<const Iterator*>
//{
//    typedef typename Iterator::difference_type difference_type;
//    typedef typename Iterator::value_type value_type;
//    typedef typename Iterator::pointer pointer;
//    typedef typename Iterator::reference reference;
//    typedef typename Iterator::iterator_category iterator_category;
//};
//
//template<typename Category, typename T>
//class MyIterator {
//
//};

#endif // !MY_ITERATOR_HPP