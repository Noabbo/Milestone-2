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
        if (endString.find("end") == 0)
        StringReverser {
            this->solver = new StringReverser();
            string problem = vectorToString(data);
            string solution = this->solver->solve(problem);
            auto rel = write(client_socket, solution.c_str(), solution.size() + 1);
            if (rel < 0) {
                throw "error writing to socket";
            }
            break;
        } else {
            data.push_back(endString);
        }

    }

}