#ifndef TEMPLATE_TREAD_H
#define TEMPLATE_TREAD_H
#include <process.h>
#include <Windows.h>
#include <mutex>

class TestThread
{
public:
    static void createThread()
    {
        for (int i = 0; i < 3; i++)
        {
            uintptr_t t = ::_beginthreadex(NULL, 0, thread, NULL, 0, NULL);
            ::CloseHandle((HANDLE)t);
        }
        getchar();
    }

private:
    static unsigned int __stdcall thread(void*)
    {
        printf("current Thread ID = %d\r\n", ::GetCurrentThreadId());
        return 0;
    }
};
#endif // !TEMPLATE_TREAD_H