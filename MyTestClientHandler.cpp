
//
// Created by noa on 17/01/2020.
//


#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socketClient) {
    cout << "enter client handler" << endl;
    vector<string> data;
    while (true) {
        //Wait to listen from the client.
        char buffer[1024] = "";
        read(socketClient, buffer, sizeof(buffer));
        string endString = "";
        endString = buffer;
        auto it = endString.find("\n");
        string line = endString.substr(0, it);
        cout << line << endl;
        if (endString.find("end")) {
            this->solver = new StringReverser();
            string solution = this->solver->solve(data);
            auto rel = write(socketClient, solution.c_str(), solution.size() + 1);
            if (rel < 0) {
                throw "error writing to socket";
            }
            break;
        } else {
            data.push_back(endString);
        }
    }
}