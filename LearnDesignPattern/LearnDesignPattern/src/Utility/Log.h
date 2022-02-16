#pragma once

#include <vector>
#include <iostream>

class Log
{
    using cstr = const std::string&;
public:
    static void logDebug(cstr _msg)
    {
        std::cout << _msg.c_str() << std::endl;
    }

    static void logDebug(cstr _msg, cstr _func, unsigned int _line, cstr _file)
    {
        size_t index = _file.find_last_of('\\');
        std::string fineName = index < 0 ? _file : _file.substr(index + 1);
        std::cout << _msg.c_str() << " [func->" << _func << "] [line->" << _line << "] [file->" << fineName << "]" << std::endl;
    }

private:

};
