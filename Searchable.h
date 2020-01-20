//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H

#include <vector>
#include "State.h"
template <class T> class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* obj) = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* obj) = 0;
};


#endif //MILESTONE_2_SEARCHABLE_H
