//
// Created by noa on 17/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H

#include <iostream>
#include <fstream>
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int socket, istream in, ostream out) = 0;
};


#endif //MILESTONE_2_CLIENTHANDLER_H
