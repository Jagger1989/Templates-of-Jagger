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

    // .at()��operator[]����Ԫ�ص�����
    {
        int a = list.at(0); // ��������Խ���飬Խ��ʱ���쳣��Խ����Ա�try catch��try catch�����ܴ�
        int b = list[0]; // ��������Խ���飬Ч�ʸ��ߣ�Խ�缴����

        std::vector<std::string> v;
        v.reserve(10); // Ԥ���ռ䣬��ʱ��û�д���Ԫ�أ�������at��[]���ʣ���Խ��
        //std::cout << "v.size = " << v.size() << std::endl; // size����0
        v.push_back("a");
        v.push_back("b");
        v.push_back("c");

        //std::string ttt = v.at(5); // Խ��
        //std::string ttt = v[%]; // Խ��

        std::vector<std::string> v1;
        v1.resize(10); // ������Ԫ�أ����Է���
        //v1.resize(10, "a"); // �ڶ���������Ҫ���������е���Ԫ�أ�������������ʡ�ԣ���ô�͵���Ԫ�ض����Ĭ�Ϲ��캯��
        //std::cout << "v1.size = " << v1.size() << std::endl; // size���10����push�������׷��
    }

    list.pop_back();
    list.clear();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(list.begin() + 1); // ����Ϊ������

    // remove_if
    {
        std::vector<std::wstring> listW;
        listW.push_back(L"1123123123c++");
        listW.push_back(L"ASDFASDF++");
        listW.push_back(L"11231XCVBXCV23123c++");
        listW.push_back(L"CCCCCCCCCCCCCC++");
        listW.push_back(L"1123123123c++");

        // ΪʲôҪ�÷º���������eraseҪ�������������������޷����Σ�ʹ�÷º�������ʵ�ִ���
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
            listW.end()); // remove_if������������Ԫ�ط�������շ��ز��������������һ��Ԫ����һ��iterator
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
        //std::cout << *it << std::endl; // ����Ԫ��ִ����+1����
    }



}

#endif // !TEMPLATE_VECTOR_H