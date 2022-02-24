#ifndef CUSTOM_SORTLIST_HPP
#define CUSTOM_SORTLIST_HPP
#include "../Utility/common.h"
#include <list>

using namespace std;

template< typename T, typename Sequence = list<T> >
class CustomQueue {
public:
    typedef typename Sequence::iterator iterator;

    CustomQueue(){}

    CustomQueue(initializer_list<T> _paramList)
    {
        auto it = _paramList.begin();
        while (it != _paramList.end())
        {
            m_sequence.push_back(*it);
            ++it;
        }
        m_sequence.sort();
    }

    void push_back(const T& ele)
    {
        m_sequence.push_back(ele);
        m_sequence.sort();
    }

    void push_back(initializer_list<T> _paramList)
    {
        auto it = _paramList.begin();
        while (it != _paramList.end())
        {
            m_sequence.push_back(*it);
            ++it;
        }
        m_sequence.sort();
    }

    iterator begin()
    {
        return m_sequence.begin();
    }

    iterator end()
    {
        return m_sequence.end();
    }

    T operator[](int index)
    {
        auto it = m_sequence.begin();
        std::advance(it, index);
        return *it;
    }

    void clear()
    {
        m_sequence.clear();
    }

    size_t size()
    {
        return m_sequence.size();
    }

    void printAll()
    {
        auto it = m_sequence.begin();
        while (it != m_sequence.end())
        {
            cout << *it << endl;
            ++it;
        }
    }


protected:
    Sequence m_sequence;
    unsigned int index;

private:

};

template<typename T> class CustomList2 : public list<T> {
public:
    CustomList2(initializer_list<T> paramList) : list<T>(paramList)
    {

    }

    void printAll()
    {
        transform(this->begin(), this->end(), this->begin(), [&](const T& ele)-> T {
            cout << ele << endl;
            return ele;
        });
    }
};

template<typename T>
T sum(T a)
{
    return a;
}

template<typename T, typename ...Args>
T sum(T head, Args ...args)
{
    return head + sum(args...);
}

void testCustomQueue()
{
    //CustomQueue<int> q = { 1,23,3,4,15 };
    //q.printAll();

    //cout << q[1] << endl;
    //cout << q[2] << endl;
    //cout << q[3] << endl;

    //cout << "q size = " << q.size() << endl;
    //q.clear();
    //cout << "q size = " << q.size() << endl;
    //q.push_back({5,2,1,4,3});
    //q.printAll();

    //CustomList2<double> lst = {1.0,2.3,3.4};
    //lst.printAll();

    // 递归求和
    // 第一次 = 1 + sum{2, 3, 4} 调用带有Args的模板函数
    // 第二次 = 2 + sum{3, 4}    调用带有Args的模板函数
    // 第三次 = 3 + sum(4)       调用不带Args的模板函数
    int x = sum(1, 2, 3, 4);
    cout << x << endl;
}



#endif // !CUSTOM_SORTLIST_HPP