//
// Created by fanny on 19/01/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MatrixSolver.h"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "DFSAlgorithm.h"


#ifndef MILESTONE_2_MAIN_H
#define MILESTONE_2_MAIN_H

namespace boot {

    class Main {
    public:
        void main(int port) {
             /*server_side::Server *server = new MyParallelServer();
             ClientHandler *client = new MyClientHandler();
             server->open(port, client);
             delete(server);
             delete(client);*/
             for (int i = 1; i < 11; i++) {
                 vector<string> data;
                 string line;
                 fstream file;
                 string file_name = "matrix";
                 file_name += to_string(i);
                 file_name += ".txt";
                 file.open(file_name, ios::in);
                 while (getline(file, line)) {
                     if (line == "end") {
                         break;
                     }
                     data.push_back(removeSpaces(line));
                 }
                 data.pop_back();
                 auto *matrixSolver = new MatrixSolver();
                 string sol = matrixSolver->solve(data);
                 cout << sol << endl;
                 file.close();
             }
        }
        string removeSpaces(string str) {
            string newStr;
            for (char i : str) {
                if ((i != ' ') && (i != '\t') && (i != '\n') && (i != '\r')) {
                    newStr.push_back(i);
                }
            }
            return newStr;
        }
    };
}

#endif //MILESTONE_2_MAIN_H