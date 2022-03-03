//
// Created by DELL on 2022/2/22.
//

#ifndef HTTPDEMO_TCPCLIENT_H
#define HTTPDEMO_TCPCLIENT_H

#include <iostream>
class TcpClient {
private:
    const struct sockaddr_in *addr_in;
    int sock_fd;
    char buffer[BUFSIZ];
public:
    TcpClient(int port);
    void start();
};


#endif //HTTPDEMO_TCPCLIENT_H
