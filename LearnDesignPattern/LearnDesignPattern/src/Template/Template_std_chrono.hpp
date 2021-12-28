#ifndef TEMPLATE_STD_CHRONO_HPP
#define TEMPLATE_STD_CHRONO_HPP

#include "../Utility/common.h"

#include <chrono>

// std::chrono是C++11引入的日期时间处理库，其中包含3种时钟：system_clock，steady_clock，high_resolution_clock。

using namespace std;

// system_clock 用在需要得到绝对时点的场景
void testSystemLock()
{
    chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    ::Sleep(2000);
    const chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    const float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;

}

// steady_clock 用在需要得到时间间隔，并且这个时间间隔不会因为修改系统时间而受影响的场景

// high_resolution_clock high_resolution_clock是system_clock或steady_clock之一，根据情况使用

#endif //! TEMPLATE_STD_CHRONO_HPP

