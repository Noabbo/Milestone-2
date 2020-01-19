//
// Created by fanny on 19/01/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MatrixSolver.h"

#ifndef MILESTONE_2_MAIN_H
#define MILESTONE_2_MAIN_H

namespace boot {

    class main {
    public:
         main(int port) {
            Solver<vector<string>, string> *solver = new MatrixSolver();
            server_side::Server *server = new MySerialServer;
            ClientHandler *client = new MyTestClientHandler();
            server->open(port, client);
            delete(server);
            delete(client);

        }
    };
}

#endif //MILESTONE_2_MAIN_H
