#ifndef SET_P_HPP
#define SET_P_HPP
#include "../Utility/common.h"

#include <set>
using namespace std;


/*
//��ͨ���÷�ʽ����
pair<iterator,bool> insert (const value_type& val);
//��ֵ���÷�ʽ����
pair<iterator,bool> insert (value_type&& val);
//����ͨ���õķ�ʽ���� val ֵ
iterator insert (const_iterator position, const value_type& val);
//����ֵ���õķ�ʽ���� val ֵ
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