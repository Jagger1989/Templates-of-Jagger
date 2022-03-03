#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP
#include "../Utility/common.h"

#include <Windows.h>
using namespace std;

//static uint64_t size = 12550820;
static string test_str(12550820, 'S');

uint64_t timeCount(std::function<void()> func)
{
    using namespace std;
    std::chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    func();
    ::Sleep(1000);
    std::chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << timeDelta << endl;
    return timeDelta;
}

void test_vector1()
{
    std::function<void()> for_f = []()->void {
        uint64_t test = 0;
        for (char mychar : test_str) {
            test++;
        }
    };

    std::function<void()> normal_iterator_f = []()->void {
        uint64_t test = 0;
        for (auto i = test_str.begin(); i != test_str.end(); i++) {
            test++;
        }
    };

    std::function<void()> reverse_iterator_f = []()->void {
        uint64_t test = 0;
        for (auto i = test_str.rbegin(); i != test_str.rend(); i++) {
            test++;
        }
    };

    std::function<void()> const_iterator_f = []()->void {
        uint64_t test = 0;
        for (string::const_iterator i = test_str.begin(); i != test_str.end(); i++) {
            test++;
        }
    };

    std::function<void()> normal_cstyle_f = []()->void {
        uint64_t test = 0;
        char* char_ptr = const_cast<char*>(test_str.c_str());
        for (uint64_t i = 0; i < test_str.size(); i++) {
            char_ptr++;
            test++;
        }
    };

    std::function<void()> reverse_cstyle_f = []()->void {
        uint64_t test = 0;
        char* char_ptr = const_cast<char*>(test_str.c_str());
        char_ptr += test_str.size();
        for (uint64_t i = 0; i < test_str.size(); i++) {
            char_ptr--;
            test++;
        }
    };

    std::function<void()> index_f = []()->void {
        uint64_t test = 0;
        char mychar;
        for (uint64_t i = 0; i < test_str.size(); i++) {
            test++;
            mychar = test_str[i];
        }
    };

    cout << "(单位:毫秒)" << endl;
    cout << "标准for遍历用时 \t" << timeCount(for_f) << endl;
    cout << "标准iterator用时 \t" << timeCount(normal_iterator_f) << endl;
    cout << "反向iterator用时 \t" << timeCount(reverse_iterator_f) << endl;
    cout << "常量iterator用时 \t" << timeCount(const_iterator_f) << endl;
    cout << "标准C风格遍历用时 \t" << timeCount(normal_cstyle_f) << endl;
    cout << "反向C风格遍历用时 \t" << timeCount(reverse_cstyle_f) << endl;
    cout << "下标访问用时 \t" << timeCount(index_f) << endl;
}

void test_vector2()
{
    string str(99999, '*');
    auto start = chrono::system_clock().now();
    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        ++count;
    }
    auto delta = static_cast<long long>(chrono::duration_cast<chrono::microseconds>(chrono::system_clock().now() - start).count());
    cout << delta << endl;
}

#endif // !TEST_VECTOR_HPP