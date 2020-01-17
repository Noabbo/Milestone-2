//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H

#include <vector>
using namespace std;
template <class T>
class Searchable {
public:
    T getInitialState();
    bool isGoalState(T obj);
    vector<T> getAllPossibleStates(T obj);
};


#endif //MILESTONE_2_SEARCHABLE_H
