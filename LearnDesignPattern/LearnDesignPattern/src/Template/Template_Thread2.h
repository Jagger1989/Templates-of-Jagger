#ifndef TEMPLATE_THREAD_2_H
#define TEMPLATE_THREAD_2_H

#include <thread>

void testThread2()
{
    // std::this_thread::sleep_for��ƽ̨�޹أ�windows��linux�������ã�STL������庯��������
    // ::Sleep windowsƽ̨��
    for (size_t i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        printf("count = %d\r\n", i);
    }
}

#endif // !TEMPLATE_THREAD_2_H