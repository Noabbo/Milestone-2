//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H

#include<unordered_map>
#include <vector>
#include "State.h"
template <class T> class Searchable {
    unordered_map<T, State<T>*> vertex_map;
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* obj) = 0;
    virtual State<T>* getGoalState() = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* obj) = 0;
    unordered_map<string, State<string>*> getMap() {
        return this->vertex_map;
    }
};


#endif //MILESTONE_2_SEARCHABLE_H
