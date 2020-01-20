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
    FileCacheManager<Matrix> *fileCacheManager;
    MatrixSearcher *searcher;
    Matrix *searchable;
public:
    virtual string solve(Matrix p);
};


#endif //MILESTONE_2_MATRIXSOLVER_H
