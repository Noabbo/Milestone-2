//
// Created by fanny on 23/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int client_socket) {
    char buffer[1024];
    vector<string> data;
    while (true) {
        //Wait to listen from the client.
        read(client_socket, buffer, sizeof(buffer));
        string endString = buffer;
        if (endString.find("end") == 0) {
            this->solver = new MatrixSolver();
            string answer = this->solver->solve(data);
            auto rel = write(client_socket, answer.c_str(), answer.size() + 1);
            if (rel < 0) {
                throw "Error writing to socket";
            }
            break;
        } else {
            data.push_back(endString);
        }
    }
}