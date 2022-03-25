#ifndef SET_P_HPP
#define SET_P_HPP
#include "../Utility/common.h"

#include <set>
using namespace std;


/*
//普通引用方式传参
pair<iterator,bool> insert (const value_type& val);
//右值引用方式传参
pair<iterator,bool> insert (value_type&& val);
//以普通引用的方式传递 val 值
iterator insert (const_iterator position, const value_type& val);
//以右值引用的方式传递 val 值
iterator insert (const_iterator position, value_type&& val);
template <class InputIterator>
  void insert (InputIterator first, InputIterator last);
  void insert (initializer_list<value_type> il);
*/

// insert()
void testSetInsert()
{
    set<int> my_set;
}

#endif // !SET_P_HPP