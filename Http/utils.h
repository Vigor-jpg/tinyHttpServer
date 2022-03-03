//
// Created by DELL on 2022/3/2.
//
#include <vector>
#include <iostream>
#ifndef HTTPDEMO_UTILS_H
#define HTTPDEMO_UTILS_H
const int OK = 200;
const int Bad_Request = 400;

std::vector<std::string> split(std::string str,char ch);
std::string getHttpTime();
std::string getContentType(std::string url);
#endif //HTTPDEMO_UTILS_H
