#ifndef TEMPLATE_MUTEX_H
#define TEMPLATE_MUTEX_H

#include "../Utility/common.h"

#include <mutex>

/*
    C++11��׼�ⶨ����4��������
    1��std::mutex
        ��ͨ�Ļ�����, ���ܵݹ�ʹ�á�
    2��std::timed_mutex
        ��ʱ�����������ܵݹ�ʹ��
    3��std::recursive_mutex
        �ݹ黥����
    4��std::recursive_timed_mutex
        ����ʱ�ĵݹ黥����
*/

class TestMutex
{
public:

private:
};

void testMutex()
{
    std::mutex my_mutex;
    // ������lock������������ڣ�����ʱ����
    // ����������ٽ�������Ϊ�׳��쳣��return�Ȳ�������û�н������˳������⡣����ؼ��˳���Ա��дMutex��ص��쳣������롣
    std::lock_guard<std::mutex> lock(my_mutex);

    // ��������������������������������߳�ռ�У���ǰ�����߳�Ҳ���ᱻ�����������ɸú������÷���false��
    // ����û������Ѿ�����ǰ�����߳���ס��������������
    my_mutex.try_lock();

    // ���ص�ǰ���
    auto handler = my_mutex.native_handle();
}

#endif // !TEMPLATE_MUTEX_H