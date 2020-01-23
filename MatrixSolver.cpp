//
// Created by noa on 19/01/2020.
//

#include "MatrixSolver.h"
MatrixSolver::MatrixSolver(vector<string> matrix) {
    auto it = prev(matrix.end());
    string end = *it;
    it = prev(it);
    string start = *it;
    matrix.erase(it, matrix.end());
    this->searchable = new Matrix(matrix, start, end);
}

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
