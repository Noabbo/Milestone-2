//
// Created by noa on 17/01/2020.
//

#include "StringReverser.h"

// reverses given string
string StringReverser::solve(vector<string> p) {
    string answer = vectorToString(p);
    reverse(answer.begin(), answer.end());
    return answer;
}
string StringReverser::vectorToString(vector<string> matrix) {
    string s = "";
    vector<string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        s += (*it);
    }
    return s;
}