//
// Created by noa on 17/01/2020.
//


#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int client_socket) {
    char buffer[1024];
    vector<string> data;

    while (true) {
        //Wait to listen from the client.
        read(client_socket, buffer, sizeof(buffer));
        string endString = buffer;
        if (endString.find("end") == 0) {
            this->solver = new MatrixSolver(data);
            break;
        } else {
            data.push_back(endString);
        }

    }

}
