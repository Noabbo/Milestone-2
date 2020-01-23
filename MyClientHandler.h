//
// Created by fanny on 23/01/2020.
//

#ifndef MILESTONE_2_MYCLIENTHANDLER_H
#define MILESTONE_2_MYCLIENTHANDLER_H


#include <string>
#include "ClientHandler.h"
#include "MatrixSolver.h"
#include "StringReverser.h"
#include <unistd.h>
using namespace std;
class MyClientHandler : public ClientHandler {
    CacheManager<string, string>* fileCacheManager;
    Solver<vector<string>, string> *solver;
public:
    virtual void handleClient(int client_socket);
    string vectorToString (vector<string> matrix);
};


#endif //MILESTONE_2_MYCLIENTHANDLER_H
