//
// Created by noa on 19/01/2020.
//

#include "MatrixSearcher.h"

MatrixSearcher::MatrixSearcher() {
    this->evaluatedNodes = 0;
}

State<Matrix> MatrixSearcher::popOpenList() {
    this->evaluatedNodes++;
    State<Matrix> state = this->openList.top();
    this->openList.pop();
    return state;
}

int MatrixSearcher::OpenListSize() {
    return this->openList.size();
}

int MatrixSearcher::getNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}
