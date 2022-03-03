#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <cstring>
#include <pthread.h>
#include "Http/MyHttpServer.h"
#include "Http/utils.h"
using namespace std;
int main(void) {
    MyHttpServer server(7000);
    server.start();
}
