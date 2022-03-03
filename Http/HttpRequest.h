//
// Created by DELL on 2022/2/20.
//

#ifndef HTTPDEMO_HTTPREQUEST_H
#define HTTPDEMO_HTTPREQUEST_H

#include <iostream>
class HttpRequest {
private:
    std::string Head;
    std::string Accept;
    std::string Connection;
public:
    void setHead(std::string head);
    void setAccept(std::string Accept);
    void setConnection(std::string connection);
};

#endif //HTTPDEMO_HTTPREQUEST_H
