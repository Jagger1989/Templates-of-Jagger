#ifndef TEMPLATE_VECTOR_H
#define TEMPLATE_VECTOR_H
#include <algorithm>

#include "../Utility/common.h"


class TestVector
{
public:

private:
};

void testVector()
{
    std::vector<int> list =
    {
        1,2,3,4
    };

    // .at()和operator[]访问元素的区别
    {
        int a = list.at(0); // 会做数组越界检查，越界时抛异常，越界可以被try catch（try catch开销很大）
        int b = list[0]; // 不做数组越界检查，效率更高，越界即崩溃

        std::vector<std::string> v;
        v.reserve(10); // 预留空间，此时并没有创建元素，不能用at或[]访问，会越界
        //std::cout << "v.size = " << v.size() << std::endl; // size还是0
        v.push_back("a");
        v.push_back("b");
        v.push_back("c");

        //std::string ttt = v.at(5); // 越界
        //std::string ttt = v[%]; // 越界

        std::vector<std::string> v1;
        v1.resize(10); // 创建了元素，可以访问
        //v1.resize(10, "a"); // 第二个参数是要加入容器中的新元素，如果这个参数被省略，那么就调用元素对象的默认构造函数
        //std::cout << "v1.size = " << v1.size() << std::endl; // size变成10，再push是在最后追加
    }

    list.pop_back();
    list.clear();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(list.begin() + 1); // 参数为迭代器

    // remove_if
    {
        std::vector<std::wstring> listW;
        listW.push_back(L"1123123123c++");
        listW.push_back(L"ASDFASDF++");
        listW.push_back(L"11231XCVBXCV23123c++");
        listW.push_back(L"CCCCCCCCCCCCCC++");
        listW.push_back(L"1123123123c++");

        // 为什么要用仿函数？比如erase要传入条件函数，但是无法传参，使用仿函数可以实现传参
        struct ContainsString : public std::unary_function<std::wstring, bool>
        {
            ContainsString(const std::wstring& wszMatch) : m_wszMatch(wszMatch) {}

            bool operator()(const std::wstring& wszStringToMatch) const
            {
                return (wszStringToMatch.find(m_wszMatch) != -1);
            }

            std::wstring m_wszMatch;
        };
        listW.erase(std::remove_if(
                listW.begin(),
                listW.end(),
                ContainsString(L"C++")
            ),
            listW.end()); // remove_if将符合条件的元素放最后，最终返回不满足条件的最后一个元素下一个iterator
        for (auto it = listW.begin(); it != listW.end(); it++)
        {
            std::cout << (*it).c_str() << std::endl;
        }
    }


    std::vector<int> list2 =
    {
        1,2,3,4
    };
    transform(list2.begin(), list2.end(), list2.begin(), [&](int point) {
        return point + 1;
    });
    for (auto it = list2.begin(); it != list2.end(); it++)
    {
        //std::cout << *it << std::endl; // 所有元素执行了+1操作
    }



}

#endif // !TEMPLATE_VECTOR_H