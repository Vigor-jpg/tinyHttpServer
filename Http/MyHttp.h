#include <sys/socket.h>
#include <iostream>
//
// Created by DELL on 2022/2/20.
//

#ifndef HTTPDEMO_MYHTTP_H
#define HTTPDEMO_MYHTTP_H


class MyHttp {
private:
    std::string Get(std::string url);
    std::string Send(std::string url,std::string requestHead);
};


#endif //HTTPDEMO_MYHTTP_H
