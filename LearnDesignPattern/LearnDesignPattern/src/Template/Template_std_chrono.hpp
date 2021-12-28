#ifndef TEMPLATE_STD_CHRONO_HPP
#define TEMPLATE_STD_CHRONO_HPP

#include "../Utility/common.h"

#include <chrono>

// std::chrono��C++11���������ʱ�䴦��⣬���а���3��ʱ�ӣ�system_clock��steady_clock��high_resolution_clock��

using namespace std;

// system_clock ������Ҫ�õ�����ʱ��ĳ���
void testSystemLock()
{
    chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    ::Sleep(2000);
    const chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    const float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;

}

// steady_clock ������Ҫ�õ�ʱ�������������ʱ����������Ϊ�޸�ϵͳʱ�����Ӱ��ĳ���

// high_resolution_clock high_resolution_clock��system_clock��steady_clock֮һ���������ʹ��

#endif //! TEMPLATE_STD_CHRONO_HPP

