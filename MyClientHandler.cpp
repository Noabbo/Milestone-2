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
    while (true) {
        read(socketClient, buffer, sizeof(buffer));
        string endString = buffer;
        auto it = endString.find("\n");
        string line = endString.substr(0, it);
        //line = removeSpaces(endString);
        if (line.find("end") != string::npos) {
            vector<string> mat;
            mat.assign(data.begin(), data.end() - 2);
            string problem = vectorToString(mat);
            problem += ".txt";
            if (this->fileCacheManager->findSolution(problem)) {
                cout << "arrive file cache manager" << endl;
                string name = vectorToString(mat);
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
                this->fileCacheManager->createProblemFile(problem);
                this->solver = new MatrixSolver();
                solution = this->solver->solve(data);
                // create file for solution
                this->fileCacheManager->insertSolution(problem, solution);
                 //Write into a file all the answers of our matrix with the matrix itself
                fstream fileAllMatrix;
                fileAllMatrix.open("AllMatrixSolutions.txt", ios::app);
                if (!fileAllMatrix) {
                    throw "error into opening file";
                }
                fileAllMatrix << problem << ".txt" << " " << solution << "_sol.txt" << endl;
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
    }
    return s;
}

// removes excess spaces and tabs in lines extracted from text file
string MyClientHandler::removeSpaces(string str) {
    string newStr;
    for (char i : str) {
        if ((i != ' ') && (i != '\t') && (i != '\n') && (i != '\r')) {
            newStr.push_back(i);
        }
    }
    return newStr;
}
