//
// Created by noa on 17/01/2020.
//

#ifndef MILESTONE_2_STRINGREVERSER_H
#define MILESTONE_2_STRINGREVERSER_H

#include <string>
#include "Solver.h"
#include "Searcher.h"
#include <algorithm>
#include "AstarAlgorithm.h"

using namespace std;

class StringReverser : public Solver<vector<string>, string> {
public:
    virtual string solve(vector<string> p);
    string vectorToString(vector<string> p);
};


#endif //MILESTONE_2_STRINGREVERSER_H
