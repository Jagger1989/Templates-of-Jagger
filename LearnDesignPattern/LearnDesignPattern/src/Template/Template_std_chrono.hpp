#ifndef TEMPLATE_STD_CHRONO_HPP
#define TEMPLATE_STD_CHRONO_HPP

#include "../Utility/common.h"

#include <chrono>
#include <ctime>

// std::chrono是C++11引入的日期时间处理库，其中包含3种时钟：system_clock，steady_clock，high_resolution_clock。

using namespace std;

// system_clock 用在需要得到绝对时点的场景
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
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // 获取当前时间，time_point格式
    std::time_t oldTime = time(nullptr); // c的获取当前时间函数 头文件 ctime
    std::time_t newTime = std::chrono::system_clock::to_time_t(start);

    cout << newTime << endl;
}

// steady_clock 用在需要得到时间间隔，并且这个时间间隔不会因为修改系统时间而受影响的场景
void testSteady_clock()
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    ::Sleep(2000);

    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

    auto interval1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);     // 纳秒
    auto interval2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);    // 微秒
    auto interval3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);    // 毫秒
    auto interval4 = std::chrono::duration_cast<std::chrono::seconds>(end - start);         // 秒
    auto interval5 = std::chrono::duration_cast<std::chrono::minutes>(end - start);         // 分
    auto interval6 = std::chrono::duration_cast<std::chrono::hours>(end - start);           // 时

    cout << interval1.count() << endl;
    cout << interval2.count() << endl;
    cout << interval3.count() << endl;
    cout << interval4.count() << endl;
    cout << interval5.count() << endl;
    cout << interval6.count() << endl;
}

// high_resolution_clock high_resolution_clock是system_clock或steady_clock之一，根据情况使用

#endif //! TEMPLATE_STD_CHRONO_HPP

