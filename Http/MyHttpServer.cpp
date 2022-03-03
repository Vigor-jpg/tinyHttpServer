//
// Created by DELL on 2022/3/1.
//

#include "MyHttpServer.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/socket.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <map>

MyHttpServer::MyHttpServer(int port) {
    struct sockaddr_in *ad =new struct sockaddr_in;
    ad->sin_port = htons(port);
    ad->sin_addr.s_addr = htonl(INADDR_ANY);
    ad->sin_family = AF_INET;
    this->addr_in = ad;
}
void MyHttpServer::executeErr(int fd, int num) {

}
void* MyHttpServer::acceptRequest(void* args) {
    std::cout << "acceptRequest : enter"<<std::endl;
    char buffer[BUFSIZ];
    int len = 0;
    int fd = *(int *)args;
    std::stringstream stream;
    if((len = recv(fd,buffer,BUFSIZ,0)) < 0){
        perror("read err!");
    }
    buffer[len] = 0;
    stream<<buffer;
    std::string head;
    getline(stream,head);
    std::vector<std::string> headV = split(head,' ');
    std::cout << "acceptRequest : "<<head<<std::endl;
    if(headV.size() != 3){
        std::cout << "acceptRequest : head err!"<<std::endl;
        for(std::string str:headV){
            std::cout << str<<std::endl;
        }
        executeErr(fd,Bad_Request);
        exit(0);
    }
    std::map<std::string,std::string> m;
    /*while(head != "\r\t"){
        getline(stream,head);
        std::vector<std::string> vh = split(head,':');
        std::cout << head <<std::endl;
        if(vh.size() != 2){
            std::cout << "acceptRequest : head err!" <<std::endl;
            executeErr(fd,Bad_Request);
        }
        m[vh[0]] = vh[1];
    }*/
    executeRequest(fd,headV[0],headV[1],headV[2],m);
}
void MyHttpServer::executeGet(int fd,std::string url, std::map<std::string, std::string> &m) {
    std::cout << "executeGet"<<std::endl;
    std::string path(get_current_dir_name());
    path = path+"/ROOT"+url;
    std::fstream file;
    std::string head = "";
    file.open(path,std::ios::in);
    std::cout << "executeGet : file path is "<<url<<std::endl;
    if(!file.is_open()){
        std::cout << "executeGet : can't find the file"<<std::endl;
    }
    file.seekg(0,file.end);
    long long length = file.tellg();
    head =head + "HTTP/1.1 200 OK\r\n";
    head += "Date:"+getHttpTime()+"\r\n";
    head += "Content-Type:"+getContentType(url)+"\r\n";
    head += "Content-Length:"+std::to_string(length)+"\r\n";
    head += "\r\n";
    file.seekg(file.beg);
    char content[BUFSIZ-head.size()];
    head += content;
    file.read(content,sizeof(content));
    //file >> content;
    //head = content;
    char ch[BUFSIZ];
    memcpy(ch,head.c_str(),head.size());
    memcpy(ch+head.size(),content,sizeof(content));
    std::cout <<sizeof(ch)<<content<<std::endl;
    send(fd,ch,sizeof(ch),0);
    while(!file.eof()){
        file.read(ch,BUFSIZ);
        send(fd,ch,sizeof(ch),0);
    }
    file.close();
    //close(fd);
    /*std::string ;
    if(file){
    }*/
}
void MyHttpServer::executePost(int fd,std::string url, std::map<std::string, std::string> &m) {

}
void MyHttpServer::executeRequest(int fd, std::string method, std::string url, std::string protocol,std::map<std::string,std::string> &m) {
    std::cout << "executeRequest"<<std::endl;
    if(method == "POST"){
        executePost(fd,url,m);
    }else if(method == "GET"){
        executeGet(fd,url,m);
    }else{
        executeErr(fd,Bad_Request);
    }
}
void MyHttpServer::start() {
    std::cout<<"-----------"<<std::endl;
    int con,one = 1;
    //poll()
    this->state = true;
    if((this->sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket create error !");
    }
    if (setsockopt(this->sock_fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
        close(this->sock_fd);
        return;
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
    while(this->state){
        int *con = new int{0};
        std::cout << "start to accept !!"<<std::endl;
        *con = accept(this->sock_fd,(struct sockaddr*) &client_addr,&length);
        if(*con < 0){
            perror("socket accept error !");
            continue;
        }
        std::cout << "accept !! con = "<<*con<<std::endl;
        pthread_t *tid = new pthread_t;

        int ret = pthread_create(tid, NULL,acceptRequest,con);
        if(ret != 0) {
            perror("thread create error !");
        }
        std::cout << "thread has been created !!"<<std::endl;
    }
    std::cout << this->state<<std::endl;
}