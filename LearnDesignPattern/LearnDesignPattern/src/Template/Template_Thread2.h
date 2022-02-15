#ifndef TEMPLATE_THREAD_2_H
#define TEMPLATE_THREAD_2_H

#include <thread>

void testThread2()
{
    // std::this_thread::sleep_for与平台无关，windows或linux都可以用，STL负责具体函数的链接
    // ::Sleep windows平台用
    for (size_t i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        printf("count = %d\r\n", i);
    }
}

#endif // !TEMPLATE_THREAD_2_H