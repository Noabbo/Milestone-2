//
// Created by fanny on 19/01/2020.
//

#include "MySerialServer.h"

bool ServerExist = true;
//Create the server
void MySerialServer::open(int port, ClientHandler clientHandler) {
    //Creation of the socket
    char buffer[1024];
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
    if (listen(socketfd, MAX_CONNECTED_CLIENTS) == -1) {
        throw "Error during listening command";
    }
    while (true) {
        //Accepting the client
        cout << "Waiting for acceptation " << port << endl;
        int client_socket = accept(socketfd, (struct sockaddr *) &serverAddress, (socklen_t *) &serverAddress);
        if (client_socket == -1) {
            throw "Error- didn't accept client";
        }
    }
    // The server keep listening to the client.
    while (ServerExist) {
        //Wait to listen from the client.
        int res = read(client_socket, buffer, sizeof(buffer));
        // the server sent information
        if (buffer[0] != '\0') {
            mutex_lock.lock();
            vector<Variable>::iterator it;
            int i = 0;
            //Create the string we receive from the buffer
            for (it = orderVars.begin(); it != orderVars.end(); it++) {
                string bufferLine = "";
                while (buffer[i] != ',') {
                    bufferLine += buffer[i];
                    i++;
                }
                //Split the "."
                i++;
                //Update each element of our map with the value receive from the server.
                it->setValue(atof(bufferLine.c_str()));
                string name = it->getName();
                if (game_configuration.find(name) != game_configuration.end())  {
                    game_configuration.at(name).setValue(atof(bufferLine.c_str()));
                }
            }
            mutex_lock.unlock();
        }
        if (ClientDone) {
            break;
        }
    }
    close(socketfd);
}

void MySerialServer::stop() {

}