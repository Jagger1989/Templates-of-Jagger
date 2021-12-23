#ifndef TEMPLATE_MUTEX_H
#define TEMPLATE_MUTEX_H

#include "../Utility/common.h"

#include <mutex>

/*
    C++11标准库定义了4个互斥类
    1、std::mutex
        普通的互斥锁, 不能递归使用。
    2、std::timed_mutex
        定时互斥锁，不能递归使用
    3、std::recursive_mutex
        递归互斥锁
    4、std::recursive_timed_mutex
        带定时的递归互斥锁
*/

class TestMutex
{
public:

private:
};

void testMutex()
{
    std::mutex my_mutex;
    // 上锁绑定lock对象的生命周期，销毁时解锁
    // 这避免了在临界区中因为抛出异常或return等操作导致没有解锁就退出的问题。极大地简化了程序员编写Mutex相关的异常处理代码。
    std::lock_guard<std::mutex> lock(my_mutex);

    // 尝试锁定互斥锁。如果互斥锁被其他线程占有，则当前调用线程也不会被阻塞，而是由该函数调用返回false；
    // 如果该互斥锁已经被当前调用线程锁住，则会产生死锁。
    my_mutex.try_lock();

    // 返回当前句柄
    auto handler = my_mutex.native_handle();
}

#endif // !TEMPLATE_MUTEX_H