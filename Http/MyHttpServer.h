//
// Created by DELL on 2022/3/1.
//

#ifndef HTTPDEMO_MYHTTPSERVER_H
#define HTTPDEMO_MYHTTPSERVER_H

#include <iostream>
#include <sstream>
#include <map>
class MyHttpServer {
private:
    struct sockaddr_in *addr_in;
    int sock_fd;
    char buffer[BUFSIZ];
    bool state;
    std::string url;
public:
    MyHttpServer(int port);
    void start();
    static void* acceptRequest(void *args);
    static void executeErr(int fd,int num);
    static void executeGet(int fd,std::string url,std::map<std::string,std::string> &m);
    static void executePost(int fd,std::string url,std::map<std::string,std::string> &m);
    static void executeRequest(int fd,std::string method,std::string url,std::string protocol,std::map<std::string,std::string> &m);
};

#endif //HTTPDEMO_MYHTTPSERVER_H
