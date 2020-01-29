//
// Created by fanny on 19/01/2020.
//
#include <chrono>
#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *clientHandler)
{
    //Intialization of the time out
    struct timeval time;
    time.tv_sec = 60;
    time.tv_usec = 0;

    //initialization of the socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        throw "error - could not create a socket";
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    //Case the bind socket doesn't bind to the IP address
    if (bind(socketfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Could not bind the socket to an IP";
    }
    //Socket listen to the port
    if (listen(socketfd, 5) == -1) {
        throw "Error during listening command";
    }

    while(true) {
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &time, sizeof time);
        // accepting a client
        int addrlen = sizeof(serverAddress);
        int clientSocket = accept(socketfd, (struct sockaddr *) &serverAddress, (socklen_t *) &addrlen);
        if (clientSocket == -1) {
            throw "Error accepting new client or no new client connected";
            break;
        } else {
            cout << "New client connected" << endl;
            thread thread(&MyParallelServer::thread_adapter, this, clientSocket, clientHandler);
            thread.detach();
        }
    }
}

void MyParallelServer::thread_adapter(int sd, ClientHandler *clientHandler) {
    clientHandler->handleClient(sd);
    close(sd);
}

void MyParallelServer::stop() {
}

string MyParallelServer::vectorToString(vector<string> matrix) {
    string s = "";
    vector<string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        s += (*it);
    }
    return s;
}