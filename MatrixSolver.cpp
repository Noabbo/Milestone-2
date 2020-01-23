//
// Created by noa on 19/01/2020.
//

#include "MatrixSolver.h"

string MatrixSolver::solve(Matrix p) {
    
    return std::__cxx11::string();
}

string MatrixSolver::vectorToString(vector<string> matrix) {
    string s = "";
    vector<string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        s += (*it);
        s += "\n";
    }
    return s;
}
