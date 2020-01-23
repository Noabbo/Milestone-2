//
// Created by fanny on 19/01/2020.
//
#include "MySerialServer.h"

bool ServerExist = true;
bool timeOut = false;
bool client_is_connected = true;
//Create the server
void MySerialServer::open(int port, ClientHandler *clientHandler) {
        //Creation of the socket
        int enable = 1;
    while (!timeOut) {

        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            throw "error - could not create a socket";
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

        cout << "Waiting for acceptation " << port << endl;
        int client_socket = accept(socketfd, (struct sockaddr *) &serverAddress, (socklen_t *) &serverAddress);
        if (client_socket == -1) {
            throw "Error- didn't accept client";
        }
        StringReverser *stringReverser = new StringReverser();
        // The server keep listening to the client.
        cout << "Accepted " << port << endl;


        close(socketfd);
        cout << "received client" << endl;
    }
}


void MySerialServer::stop() {
}