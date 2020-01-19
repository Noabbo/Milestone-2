//
// Created by fanny on 19/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H

#include <mutex>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "Server.h"
#define MAX_CONNECTED_CLIENTS 10


class MySerialServer: public Server {
public:
    virtual void open(int port, ClientHandler clientHandler);
    virtual void stop();
private:
    mutex mutex_lock;
};


#endif //MILESTONE_2_MYSERIALSERVER_H
