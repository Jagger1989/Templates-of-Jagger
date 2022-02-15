#ifndef TEMPLATE_STD_CHRONO_HPP
#define TEMPLATE_STD_CHRONO_HPP

#include "../Utility/common.h"

#include <chrono>
#include <ctime>

// std::chrono��C++11���������ʱ�䴦��⣬���а���3��ʱ�ӣ�system_clock��steady_clock��high_resolution_clock��

using namespace std;

// system_clock ������Ҫ�õ�����ʱ��ĳ���
void testSystemLock1()
{
    Log::logDebug("start", __FUNCTION__, __LINE__, __FILE__);
    std::chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    ::Sleep(2000);
    std::chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;
}

void testSystemLock2()
{
    Log::logDebug("start", __FUNCTION__, __LINE__, __FILE__);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // ��ȡ��ǰʱ�䣬time_point��ʽ
    std::time_t oldTime = time(nullptr); // c�Ļ�ȡ��ǰʱ�亯�� ͷ�ļ� ctime
    std::time_t newTime = std::chrono::system_clock::to_time_t(start);

    cout << newTime << endl;
}

// steady_clock ������Ҫ�õ�ʱ�������������ʱ����������Ϊ�޸�ϵͳʱ�����Ӱ��ĳ���
void testSteady_clock()
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    ::Sleep(2000);

    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

    auto interval1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);     // ����
    auto interval2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);    // ΢��
    auto interval3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);    // ����
    auto interval4 = std::chrono::duration_cast<std::chrono::seconds>(end - start);         // ��
    auto interval5 = std::chrono::duration_cast<std::chrono::minutes>(end - start);         // ��
    auto interval6 = std::chrono::duration_cast<std::chrono::hours>(end - start);           // ʱ

    cout << interval1.count() << endl;
    cout << interval2.count() << endl;
    cout << interval3.count() << endl;
    cout << interval4.count() << endl;
    cout << interval5.count() << endl;
    cout << interval6.count() << endl;
}

// high_resolution_clock high_resolution_clock��system_clock��steady_clock֮һ���������ʹ��

#endif //! TEMPLATE_STD_CHRONO_HPP

