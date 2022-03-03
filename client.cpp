//
// Created by DELL on 2022/2/22.
//
#include <iostream>
#include <sys/socket.h>
#include "Tcp/TcpServer.h"
#include "Tcp/TcpClient.h"
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::cout << "Hello, World!" << std::endl;
    //TcpServer *tcpServer = new class TcpServer;
    //tcpServer->serverInit(7673);
    cout<<"80"<<endl;
    //tcpServer->start();
    TcpClient tcpClient(7678);
    tcpClient.start();
    return 0;
}