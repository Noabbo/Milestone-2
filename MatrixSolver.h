//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_MATRIXSOLVER_H
#define MILESTONE_2_MATRIXSOLVER_H

#include <string>
#include "Solver.h"
#include "Searcher.h"
#include "MatrixSearcher.h"
#include "FileCacheManager.h"
#include "Matrix.h"

using namespace std;

class MatrixSolver : public Solver<vector<string>, string> {
    MatrixSearcher *searcher;
    Matrix *searchable;
public:
    MatrixSolver(vector<string> matrix);
    virtual string solve(Matrix p);
    string vectorToString (vector<string> matrix);
    ~MatrixSolver() {
        delete(this->searchable);
        delete(this->searcher);
    }
};


#endif //MILESTONE_2_MATRIXSOLVER_H
