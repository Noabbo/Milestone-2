//
// Created by noa on 23/01/2020.
//

#ifndef MILESTONE_2_DFSALGORITHM_H
#define MILESTONE_2_DFSALGORITHM_H


#include "MatrixSearcher.h"

class DFSAlgorithm : public MatrixSearcher {
    virtual unordered_map<string, double> search(Matrix searchable);
};


#endif //MILESTONE_2_DFSALGORITHM_H
