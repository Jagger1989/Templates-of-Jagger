#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

char* getLocalTime()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    char ts[1024] = { 0 };
    _snprintf_s(ts, sizeof(ts), "%4d-%02d-%2d %02d:%02d:%02d %03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    return ts;
}

int main()
{
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT winSize = { 0, 0 };
    winSize.Right = 80 - 1;
    winSize.Bottom = 40 - 1;

    SetConsoleWindowInfo(outputHandle, 1, &winSize);
    SetConsoleWindowInfo(outputHandle, 1, &winSize);

    SOCKADDR_IN saddr;
    SOCKADDR_IN caddr;
    saddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(55555);

    char RecvBuffer[100];
    WORD wVersionRequested;
    WSADATA wsaData;
    DWORD dwErrorCode;
    wVersionRequested = MAKEWORD(2, 2);
    dwErrorCode = WSAStartup(wVersionRequested, &wsaData);
    if (dwErrorCode != 0)
    {
        return 0;
    }

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == SOCKET_ERROR)
    {
        closesocket(sockfd);
        WSACleanup();
        return 0;
    }

    // 设置端口复用
    char on = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    dwErrorCode = bind(sockfd, (SOCKADDR *)&saddr, sizeof(SOCKADDR));
    if (dwErrorCode != 0)
    {
        closesocket(sockfd);
        WSACleanup();
        return 0;
    }

    int length = sizeof(SOCKADDR);
    while (true)
    {
        printf("----------waiting for data----------\n");
        int retNum = 0;
        memset(RecvBuffer, 0, 100);
        retNum = recvfrom(sockfd, RecvBuffer, 100, 0, (SOCKADDR *)&caddr, &length);
        if (retNum <= 0)
        {
            printf("time: %s\n", getLocalTime());
            printf("error!\n");
        }
        else
        {
            printf("time: %s\n", getLocalTime());
            printf("data: %s\n", RecvBuffer);
        }
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}