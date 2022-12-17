#ifndef MY_UDP_SERVER_H
#define MY_UDP_SERVER_H

#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <string>
#include <thread>

class MyUDPServer
{
public:
    MyUDPServer();
    MyUDPServer(const std::string& addr, unsigned short port);
    ~MyUDPServer();

    bool prepare();
    std::function<void()> getRun();
    void start();
    void stop();

private:
    SOCKET m_socket;
    SOCKADDR_IN m_saddr;
    char m_recvBuf[1024 * 9];
    std::thread* m_thread;
    bool m_running;
};

#endif // MY_UDP_SERVER_H