//
// Created by fanny on 23/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int client_socket) {
    char buffer[1024];
    vector<string> data;
    string sol;
    while (true) {
        //Wait to listen from the client.
        read(client_socket, buffer, sizeof(buffer));
        string endString = buffer;
        if (!endString.find("end")) {
            if (this->fileCacheManager->findSolution(vectorToString(data))) {
                string name = vectorToString(data);
                name += "_sol";
                fstream file;
                file.open(this->fileCacheManager->get(name), ios::in | ios::binary);
                if (!file) {
                    throw "Error - file didn't open";
                }
                getline(file, sol);
                file.close();
            } else {
                // create file for matrix
                vector<string> mat;
                mat.assign(data.begin(), data.end()-2);
                this->fileCacheManager->createProblemFile(vectorToString(mat));
                this->solver = new MatrixSolver();
                sol = this->solver->solve(data);
                // create file for solution
                this->fileCacheManager->insertSolution(vectorToString(mat), sol);
            }
            auto rel = write(client_socket, sol.c_str(), sol.size() + 1);
            if (rel < 0) {
                throw "Error writing to socket";
            }
            break;
        } else {
            data.push_back(endString);
        }
    }
}

string MyClientHandler::vectorToString(vector<string> matrix) {
    string s = "";
    vector<string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        s += (*it);
        //s += "\n";
    }
    return s;
}