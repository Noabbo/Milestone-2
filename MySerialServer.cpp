//
// Created by fanny on 19/01/2020.
//
#include <limits>
#include "MySerialServer.h"

bool timeOut = false;
bool firstConnection = true;
//Create the server
void MySerialServer::open(int port, ClientHandler *clientHandler) {
    //Creation of the socket
    int enable = 1;
    // sets timeout's definition
    timeval client_timeout ;
    client_timeout.tv_sec = 0;
    client_timeout.tv_usec = 0 ;
    timeval server_timeout ;
    while (!timeOut) {

        int socketfd = socket(AF_INET, SOCK_STREAM, 0), newSocketfd;
        if (socketfd == -1) {
            throw "error - could not create a socket";
        }
        if(firstConnection) {
            server_timeout.tv_sec = std::numeric_limits<int>::max() ;
            firstConnection = false ;
        }  else {
            server_timeout.tv_sec = 5;
        }

        sockaddr_in serverAddress;

        // Sets the socket to be reused
        if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) != 0) {
            throw "Cannot reuse address";
        }
        //Port already in use
        if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) != 0) {
            throw "Cannot reuse port";
        }
        //Didn't succeed to open the socket
        if (socketfd < 0) {
            throw "cannot open socket, please try again";
        }

        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons(port);
        cout << port << endl;

        //Case the bind socket doesn't bind to the IP address
        if (bind(socketfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            throw "Could not bind the socket to an IP";
        }
        //Socket listen to the port
        if (listen(socketfd, 5) == -1) {
            throw "Error during listening command";
        }
        //Accepting the client
        cout << socketfd << endl;

        server_timeout.tv_usec = 0;
        setsockopt(socketfd,SOL_SOCKET,SO_RCVTIMEO,(char *)&server_timeout, sizeof(server_timeout));
        // setsockopt(newSocketfd,SOL_SOCKET,SO_RCVTIMEO,(char *)&client_timeout, sizeof(client_timeout));

        // accept the connection request

        cout << "Waiting for acceptation " << port << endl;
        int client_socket = accept(socketfd, (struct sockaddr *) &serverAddress, (socklen_t *) &serverAddress);
        if (client_socket == -1) {
            throw "Error- didn't accept client";
        }
        // if (newSocketfd < 0)
        //{
        if(errno == EWOULDBLOCK)
        {
            std::cout<<"timeout!"<<std::endl;
            timeOut = true;
        }
        // }
        //The client has been accepted by the server, the client handle find the solution send to the server
        cout << "Accepted " << port << endl;
        MyTestClientHandler *client = new MyTestClientHandler();
        client->handleClient(client_socket);

        close(socketfd);
        cout << "received client" << endl;
    }
}


void MySerialServer::stop() {
}