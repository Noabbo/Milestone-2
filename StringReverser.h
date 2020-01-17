//
// Created by noa on 17/01/2020.
//

#ifndef MILESTONE_2_STRINGREVERSER_H
#define MILESTONE_2_STRINGREVERSER_H

#include <string>
#include "Solver.h"
using namespace std;

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string p);
};


#endif //MILESTONE_2_STRINGREVERSER_H
