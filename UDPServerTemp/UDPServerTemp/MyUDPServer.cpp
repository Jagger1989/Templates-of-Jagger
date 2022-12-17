#include "MyUDPServer.h"
#include "Util.h"

MyUDPServer::MyUDPServer()
{
    m_saddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    m_saddr.sin_family = AF_INET;
    m_saddr.sin_port = htons(55555);
}

MyUDPServer::MyUDPServer(const std::string& addr, unsigned short port)
{
    m_saddr.sin_addr.S_un.S_addr = inet_addr(addr.c_str());
    m_saddr.sin_family = AF_INET;
    m_saddr.sin_port = htons(port);
}

MyUDPServer::~MyUDPServer()
{
    if (m_thread != nullptr)
    {
        delete m_thread;
        m_thread = nullptr;
    }
    closesocket(m_socket);
    WSACleanup();
}

bool MyUDPServer::prepare()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    DWORD dwErrorCode;
    wVersionRequested = MAKEWORD(2, 2);
    dwErrorCode = WSAStartup(wVersionRequested, &wsaData);
    if (dwErrorCode != 0)
    {
        return false;
    }

    // 注意socket要在WSAStartup之后实例化
    m_socket = socket(AF_INET, SOCK_DGRAM, 0);

    char on = 1;
    setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    dwErrorCode = bind(m_socket, (SOCKADDR *)&m_saddr, sizeof(SOCKADDR));
    if (dwErrorCode != 0)
    {
        return false;
    }
    return true;
}

std::function<void()> MyUDPServer::getRun()
{
    return [this]()->void {
        int length = sizeof(SOCKADDR);
        while (this->m_running)
        {
            printf("----------waiting for data----------\n");
            int retNum = 0;
            memset(this->m_recvBuf, 0, 100);
            retNum = recvfrom(this->m_socket, this->m_recvBuf, sizeof(this->m_recvBuf), 0, (SOCKADDR *)&this->m_saddr, &length);
            std::string recv_str = UTF8ToString(std::string(&this->m_recvBuf[0], &this->m_recvBuf[strlen(this->m_recvBuf)]));

            printf("time: %s\n", getLocalTime());
            if (retNum <= 0)
            {
                printf("0 bytes received !\n");
            }
            else
            {
                printf("lenth: %d\ndata: %s\n", retNum, recv_str.c_str());
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    };
}

void MyUDPServer::start()
{
    m_running = true;
    m_thread = new std::thread(getRun());
}

void MyUDPServer::stop()
{
    m_running = false;
    m_thread->join();
}