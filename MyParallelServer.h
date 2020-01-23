//
// Created by fanny on 19/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H
#include <mutex>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "Server.h"
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include "MyClientHandler.h"
#define TRUE   1
#define MAX_CONNECTED_CLIENTS 10

class MyParallelServer: public server_side::Server {
public:
    virtual void open(int port, ClientHandler *clientHandler);
    virtual void stop();
};


#endif //MILESTONE_2_MYPARALLELSERVER_H
