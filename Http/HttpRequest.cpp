//
// Created by DELL on 2022/2/20.
//

#include "HttpRequest.h"
#include <ios>
void HttpRequest::setHead(std::string head){
    this->Head = head;
}
void HttpRequest::setAccept(std::string Accept){
    this->Accept = Accept;
}
void HttpRequest::setConnection(std::string connection){
    this->Connection = Connection;
}