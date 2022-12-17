#include <stdio.h>

#include "MyUDPServer.h"

int main()
{
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT winSize = { 0, 0 };
    winSize.Right = 80 - 1;
    winSize.Bottom = 40 - 1;

    SetConsoleWindowInfo(outputHandle, 1, &winSize);
    SetConsoleWindowInfo(outputHandle, 1, &winSize);

    MyUDPServer mus("127.0.0.1", 55555);
    if (!mus.prepare())
    {
        return 0;
    }
    mus.start();

    while (true)
    {
        printf("I'm still alive !\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
    return 0;
}