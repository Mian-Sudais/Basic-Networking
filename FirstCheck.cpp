#include<iostream>
#include<winsock2.h>

// #pragma comment(lib, "ws2_32.lib")

class NetworkingSock
{
    WSADATA wsaData;
    bool isInitialized;
public:
    NetworkingSock() : isInitialized(false)
    {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            std::cout<<"WSA Failed To Start.\n";
        }
        else
        {
            std::cout<<"WSA Startup Successfully.\n";
            isInitialized = true;
            if (LOBYTE(wsaData.wVersion) != 2)
            {
                std::cout<<"ERROR: WSA Version 2 is not Available. Shutting down engine.\n";
                WSACleanup();
                isInitialized = false;
            }
            else
            {               
            std::cout<<"SUCCESS: WSA Version 2 is Available. Ready for sockets!\n";
            isInitialized = true;
            }
        }
    }
    ~NetworkingSock()
    {
        if (isInitialized)
        {
        WSACleanup();
        std::cout<<"WSA Has been Cleaned Successfully.\n";
        }
        else
        {
            std::cout<<"WSA is never been started.";
        }
    }
    NetworkingSock(const NetworkingSock&) = delete;
    NetworkingSock& operator=(const NetworkingSock&) = delete;
};

int main()
{
    NetworkingSock ns;
}