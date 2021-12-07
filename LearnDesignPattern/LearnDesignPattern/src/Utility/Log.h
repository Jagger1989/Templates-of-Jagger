#pragma once

#include <vector>
#include <iostream>

class Log
{
public:
    static void logDebug(std::string _msg)
    {
        std::cout << _msg.c_str() << std::endl;
    }
private:

};
