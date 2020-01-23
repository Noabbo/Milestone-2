//
// Created by noa on 17/01/2020.
//


#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int client_socket) {
    char buffer[1024];
    string data;

    while (true) {
        //Wait to listen from the client.
        read(client_socket, buffer, sizeof(buffer));
        string endString = buffer;
        if (endString.find("end") == 0) {
            this->solver = new StringReverser();
            string answer = this->solver->solve(data);
            auto rel = write(client_socket, answer.c_str(), answer.size() + 1);
            if (rel < 0) {
                throw "error writing to socket";
            }
            break;
        } else {
            data += endString;
        }

    }

}
