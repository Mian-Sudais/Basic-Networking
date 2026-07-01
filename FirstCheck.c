#include<winsock2.h>
#include<stdbool.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")
int main()
{
    WSADATA wsadata;
    bool check = WSAStartup(MAKEWORD(2,2), &wsadata) != 0;
    printf("The OutPut for Check is: %d\n", check);
    if (check)
    {
        fprintf(stderr, "WSAStartup Failed\n");
        exit(1);
    }
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) 
    {
        fprintf(stderr, "Version 2.2 of Winsock not available.\n");
        WSACleanup();
        exit(2);
    }
    printf("Fuckingly NOthing Happens!!!!\nThis basically Means The code Runs Correctly...\n");
    WSACleanup();
    return 0;
}