
//
// Created by noa on 17/01/2020.
//


#include "MyTestClientHandler.h"

string MyTestClientHandler::handleClient(vector<string> data) {
    this->solver = new StringReverser();
    string problem = vectorToString(data);
    string solution = this->solver->solve(problem);
    return solution;
}

string MyTestClientHandler::vectorToString(vector<string> matrix) {
    string s = "";
    vector<string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        s += (*it);
        //s += "\n";
    }
    return s;
}