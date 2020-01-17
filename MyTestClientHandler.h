//
// Created by noa on 17/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H

#include <string>
#include "ClientHandler.h"
#include "StringReverser.h"

using namespace std;
class MyTestClientHandler : public ClientHandler {
StringReverser solver;
public:
    virtual void handleClient(int socket, istream in, ostream out);
};


#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
