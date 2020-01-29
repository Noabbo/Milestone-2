//
// Created by fanny on 23/01/2020.
//

#include "MyClientHandler.h"
MyClientHandler::MyClientHandler() {
    this->fileCacheManager = new FileCacheManager();
}

void MyClientHandler::handleClient(int socketClient) {
    char buffer[1025];
    vector<string> data;
    string solution;
    string problem = vectorToString(data);
    while (true) {
        read(socketClient, buffer, sizeof(buffer));
        string endString = buffer;
        auto it = endString.find("\n");
        string line = endString.substr(0, it);
        if (line.find("end") != string::npos) {
            if (this->fileCacheManager->findSolution(problem)) {
                string name = vectorToString(data);
                name += "_sol.txt";
                fstream file;
                file.open(this->fileCacheManager->get(name), ios::in | ios::binary);
                if (!file) {
                    throw "Error - file didn't open";
                }
                getline(file, solution);
                auto rel = write(socketClient, solution.c_str(), solution.size() + 1);
                if (rel < 0) {
                    throw "Error writing to socket";
                }
                file.close();
                break;
                //The solution need to be calculated
            } else {
                // create file for matrix
                vector<string> mat;
                mat.assign(data.begin(), data.end() - 2);
                this->fileCacheManager->createProblemFile(vectorToString(mat));
                this->solver = new MatrixSolver();
                solution = this->solver->solve(data);
                // create file for solution
                this->fileCacheManager->insertSolution(vectorToString(mat), solution);
                //Write into a file all the answers of our matrix with the matrix itself
                fstream fileAllMatrix;
                fileAllMatrix.open("AllMatrixSolutions.txt", ios::app);
                if (!fileAllMatrix) {
                    throw "error into opening file";
                }
                fileAllMatrix << vectorToString(mat) << endl;
                fileAllMatrix << solution << endl;
                fileAllMatrix.close();
                auto rel = write(socketClient, solution.c_str(), solution.size() + 1);
                if (rel < 0) {
                    throw "Error writing to socket";
                }
                break;
            }
        } else {
            data.push_back(line);
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