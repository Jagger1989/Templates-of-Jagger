#ifndef CUSTOM_QUEUE_HPP
#define CUSTOM_QUEUE_HPP
#include "../Utility/common.h"
#include <deque>

using namespace std;

template< typename T, typename Sequence = deque<T> >
class CustomQueue {
public:
    typedef typename Sequence::iterator iterator;

    CustomQueue(){}

    CustomQueue(initializer_list<int> _paramList)
    {
        auto it = _paramList.begin();
        while (it != _paramList.end())
        {
            m_sequence.push_back(*it);
            ++it;
        }
    }

    void push_back(const T& ele)
    {
        m_sequence.push_back(ele);
    }

    T pop_back()
    {
        T temp = m_sequence.back();
        m_sequence.pop_back();
        return temp;
    }

    iterator begin()
    {
        return m_sequence.begin();
    }

    iterator end()
    {
        return m_sequence.end();
    }

    T back()
    {
        return m_sequence.back();
    }


protected:
    Sequence m_sequence;

private:

};

void testCustomQueue()
{
    CustomQueue<int> q = {1,2,3,4,5};
    auto it = q.begin();
    while (it != q.end())
    {
        cout << *it << endl;
        ++it;
    }

    cout << q.pop_back() << endl;
    it = q.begin();
    while (it != q.end())
    {
        cout << *it << endl;;
        ++it;
    }
}
#endif // !CUSTOM_QUEUE_HPP