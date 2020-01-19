//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_BFSALGORITHM_H
#define MILESTONE_2_BFSALGORITHM_H

#include <string>
#include "Searcher.h"
#include "Matrix.h"
#include "MatrixSearcher.h"

using namespace std;

class BFSAlgorithm : public MatrixSearcher {
public:
    virtual string search(Matrix searchable);
};


#endif //MILESTONE_2_BFSALGORITHM_H
