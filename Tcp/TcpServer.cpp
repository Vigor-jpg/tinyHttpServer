//
// Created by DELL on 2022/2/22.
//

#include "TcpServer.h"
#include <iostream>
#include <sys/socket.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
void TcpServer::serverInit(int port) {
    struct sockaddr_in *ad =new struct sockaddr_in;
    ad->sin_port = htonl(port);
    ad->sin_addr.s_addr = inet_addr("127.0.0.1");
    ad->sin_family = AF_INET;
    this->addr_in = ad;
}
void TcpServer::start() {
    std::cout<<"-----------"<<std::endl;
    int con;
    //poll()
    if((this->sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket create error !");
    }
    std::cout << "socket created !! and socket_fd = " << this->sock_fd<< std::endl;
    int bi = 0;
    if((bi = bind(this->sock_fd,(struct sockaddr*)this->addr_in,sizeof(struct sockaddr))) < 0){
        perror("socket bind error !");
    }
    std::cout << "socket bind and bind ="<<bi<< "!!" << std::endl;
    if((bi = listen(this->sock_fd,5)) < 0){
        perror("socket listen error !");
    }
    std::cout << "socket listen !! listen = " <<bi<< std::endl;
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(struct sockaddr_in);
    while(con = accept(this->sock_fd,(struct sockaddr*) &client_addr,(socklen_t *)&length)){
        if(con < 0){
            perror("socket accept error !");
            continue;
        }

    }
    std::cout << "socket accept !!" << std::endl;
    int len = 0;
    std::string msg = "Http";
    char bu[8];
    //memcpy(buffer,&msg,sizeof(msg));
    send(con,&msg,sizeof(msg),0);
    while((len = recv(con,buffer,BUFSIZ,0)) > 0){
        std::cout<<buffer<<std::endl;
    }
    if(len < 0){
        perror("recv err!");
    }
    //close(con);
    //close(sock_fd);
}