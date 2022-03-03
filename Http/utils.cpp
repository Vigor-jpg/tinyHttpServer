//
// Created by DELL on 2022/3/2.
//
#include "utils.h"
#include <vector>
#include <iostream>
#include <string>
std::vector<std::string> split(std::string str,char ch){
    std::vector<std::string> v;
    int l = 0,r = 0;
    while(r < str.size()){
        if(str[r] == ch){
            if(l != r){
                v.push_back(str.substr(l,r-l));
            }
            l = r+1;
        }
        r++;
    }
    if(l != r){
        v.push_back(str.substr(l,r-l));
    }
    return v;
}

std::string getHttpTime(){
    time_t now = time(nullptr);
    tm* gmt = gmtime(&now);
    const char* fmt = "%a, %d %b %Y %H:%M:%S GMT";
    char tstr[30];
    strftime(tstr, sizeof(tstr), fmt, gmt);
    return tstr;
}
std::string getContentType(std::string url){
    std::vector<std::string> v = split(url,'.');
    std::string type = v[v.size()-1];
    std::string res;
    if(type == "html"){
        res = "text/html";
    }else if(type == "txt"){
        res = "text/plain";
    }else if(type == "xml"){
        res = "text/xml";
    }else if(type == "gif"){
        res = "image/gif";
    }else if(type == "jpeg"){
        res = "image/jpeg";
    }else if(type == "png"){
        res = "image/png";
    }else if(type == "xhtml"){
        res = "application/xhtml+xml";
    }else if(type == "pdf"){
        res = "application/pdf";
    }else if(type == "doc" || type == "docx"){
        res = "application/msword";
    }else if(type == "css"){
        res = "text/css";
    }else if(type == "ico"){
        res = "image/x-icon";
    }else if(type == "js"){
        res = "application/x-javascrip";
    }else{
        res = "text/*";
    }
    return res;
}