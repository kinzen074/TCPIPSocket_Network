//Kinzen 20230514 
//Initial Draft 
//Ref https://www.bilibili.com/video/BV1BQ4y1X7Wc/

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")


int main()
{
	//Initial Socket
	WSADATA wsaData;
	WORD wsaVersion = MAKEWORD(2, 0);
	WSAStartup(wsaVersion, &wsaData);//_WINSOCK_DEPRECATED_NO_WARNINGS defination is required in pre-processer


	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9999);

	int res = connect(clientSock, (sockaddr*)&addr, sizeof(addr));

	//Relase Resource
	closesocket(clientSock);
	WSACleanup();

	//Simple test
	std::cout << res << std:: endl;
	return 0;
}

