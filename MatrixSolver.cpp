//
// Created by noa on 19/01/2020.
//

#include "MatrixSolver.h"
MatrixSolver::MatrixSolver() {
    this->searcher = new AstarAlgorithm();
}

string MatrixSolver::solve(vector<string> p) {
    // extract matrix and points from vector
    auto it = prev(p.end());
    string end = *it;
    it = prev(it);
    string start = *it;
    p.erase(it, p.end());
    this->searchable = new Matrix(p, start, end);

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
