//
// Created by DELL on 2022/2/22.
//

#ifndef HTTPDEMO_TCPSERVER_H
#define HTTPDEMO_TCPSERVER_H
#include <iostream>
class TcpServer {
private:
    const struct sockaddr_in *addr_in;
    int sock_fd;
    char buffer[BUFSIZ];
public:
    void serverInit(int port);
    void start();
};


#endif //HTTPDEMO_TCPSERVER_H
