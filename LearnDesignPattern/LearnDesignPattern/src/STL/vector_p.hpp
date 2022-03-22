#ifndef VECTOR_P_HPP
#define VECTOR_P_HPP
#include "../Utility/common.h"

using namespace std;

int m_printCount = 1;

// vector 是0.5倍扩容

template<typename T>
void printfVector(const vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << "========================" << m_printCount++ << endl;
}

void testVector1()
{
    string str[] = {"Alex", "Jhon", "Robert"};
    vector<int> v1;
    //v1[0] = 1; // 数组越界 v1为空，此种只能用push_back()
    printfVector(v1);
    vector<int> v2(10); // 初始化为10个int（初始值 0）
    printfVector(v2);
    vector<float> v3(10, 0);
    printfVector(v3);
    vector<string> v4(str, str + 1); // 个人理解，param1是首地址，param2是首地址加上个数
    printfVector(v4);
}

/*
for (auto obj : list)                                   spend : 18
for_each(list.begin(), list.end(), func);               spend : 134
transform(list.begin(), list.end(), list.begin(), func) spend : 144
for (size_t i = 0; i < list.size(); i++)                spend : 2244
for (auto it = list.begin(); it != list.end(); ++it)    spend : 3842
while (it != list.end())                                spend : 3838
*/
void testVectorPerformance()
{
    vector<int> list(9999999, 1);
    std::chrono::time_point<chrono::system_clock> chronoTimeStart = chrono::system_clock::now();
    for (size_t i = 0; i < list.size(); i++)
    {
        ++list[i];
    }
    std::chrono::time_point<chrono::system_clock> chronoTimeEnd = chrono::system_clock::now();
    float timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "for (size_t i = 0; i < list.size(); i++) spend : " << timeDelta << endl;

    auto func = [&](int& obj)-> int {
        return ++obj;
    };
    chronoTimeStart = chrono::system_clock::now();
    for_each(list.begin(), list.end(), func);
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "for_each(list.begin(), list.end(), func); spend : " << timeDelta << endl;

    chronoTimeStart = chrono::system_clock::now();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        ++(*it);
    }
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "for (auto it = list.begin(); it != list.end(); ++it) spend : " << timeDelta << endl;

    auto it = list.begin();
    chronoTimeStart = chrono::system_clock::now();
    while (it != list.end())
    {
        ++(*it);
        ++it;
    }
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "while (it != list.end()) spend : " << timeDelta << endl;

    chronoTimeStart = chrono::system_clock::now();
    for (auto& obj : list)
    {
        ++obj;
    }
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "for (auto obj : list) spend : " << timeDelta << endl;

    chronoTimeStart = chrono::system_clock::now();
    transform(list.begin(), list.end(), list.begin(), func);
    chronoTimeEnd = chrono::system_clock::now();
    timeDelta = static_cast<float>(chrono::duration_cast<chrono::milliseconds>(chronoTimeEnd - chronoTimeStart).count());
    cout << "transform(list.begin(), list.end(), list.begin(), func) spend : " << timeDelta << endl;
}

#endif // !VECTOR_P_HPP