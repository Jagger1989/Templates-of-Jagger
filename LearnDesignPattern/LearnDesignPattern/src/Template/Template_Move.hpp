#ifndef TEMPLATE_MOVE_H
#define TEMPLATE_MOVE_H
#include "../Utility/common.h"
#include <vector>

void testMove()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    cout << "str addr = " << &str << endl;
    // 使用 push_back(const T&) 重载，
    // 表示我们将带来复制 str 的成本
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // 使用右值引用 push_back(T&&) 重载，
    // 表示不复制字符串；而是
    // str 的内容被移动进 vector
    // 这个开销比较低，但也意味着 str 现在可能为空。
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "V[0] = " << v[0] << std::endl;
    std::cout << "V[0] addr = " << &v[0] << std::endl;
    std::cout << "V[1] = " << v[1] << std::endl;
    std::cout << "V[1] addr = " << &v[1] << std::endl;

    // 可以知道，move语义允许一个对象在特定的情形下，取得其他对象的资源。
    // 这也就是经典的右值引用，而被引用的变量被释放。
    // move是性能优化的一种方式
}

#endif // !TEMPLATE_MOVE_H