//
// Created by DELL on 2022/2/22.
//

#include "TcpClient.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
TcpClient::TcpClient(int port) {
    struct sockaddr_in *ad =new struct sockaddr_in;
    ad->sin_port = htons(port);
    ad->sin_addr.s_addr = inet_addr("127.0.0.1");
    ad->sin_family = AF_INET;
    this->addr_in = ad;
}
void TcpClient::start() {
    if((this->sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket create error !");
    }
    std::cout << "socket created !!" << std::endl;
    if(connect(this->sock_fd,(struct sockaddr*)this->addr_in,sizeof(struct sockaddr)) < 0){
        perror("socket connect error !");
    }
    std::cout << "socket connected !!" << std::endl;
    const void *msg = "Http 1.1\n";
    send(sock_fd,msg,sizeof(msg),0);
    std::cout<<"ending !"<<std::endl;
}