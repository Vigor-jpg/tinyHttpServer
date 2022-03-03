cmake_minimum_required(VERSION 3.17)
project(httpDemo)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
#add_executable(httpDemo Tcp/TcpServer.cpp Tcp/TcpServer.h Tcp/TcpClient.cpp Tcp/TcpClient.h Tcp/tcp.cpp Tcp/tcp.h Http/HttpRequest.cpp Http/HttpRequest.h   Http/MyHttp.cpp Http/MyHttp.h  client.cpp main.cpp)
#add_executable(httpDemo Tcp/TcpServer.cpp Tcp/TcpServer.h Tcp/TcpClient.cpp Tcp/TcpClient.h Tcp/tcp.cpp Tcp/tcp.h main.cpp Http/MyHttpServer.cpp Http/MyHttpServer.h)
#include_directories("/usr/include")

add_executable(httpDemo Http/utils.h Http/utils.cpp Http/MyHttpServer.h Http/MyHttpServer.cpp main.cpp )
