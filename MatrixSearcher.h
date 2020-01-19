//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_MATRIXSEARCHER_H
#define MILESTONE_2_MATRIXSEARCHER_H

#include <queue>
#include "Searcher.h"
#include "Matrix.h"
using namespace std;

class MatrixSearcher : public Searcher<string, string>{
priority_queue<State<Matrix>> openList;
int evaluatedNodes;
protected:
    State<Matrix> popOpenList();
public:
    MatrixSearcher();
    int OpenListSize();
    int getNumberOfNodesEvaluated();
    virtual string search(Matrix searchable) = 0;
};


#endif //MILESTONE_2_MATRIXSEARCHER_H
