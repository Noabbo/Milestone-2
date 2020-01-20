//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_MATRIX_H
#define MILESTONE_2_MATRIX_H

#include <unordered_map>
#include <fstream>
#include "Searchable.h"

class Matrix : public Searchable<string> {
    unordered_map<string, State<string>*> vertex_map;
    State<string>* entry;
    State<string>* exit;
    int numOfLines;
public:
    Matrix(vector<string> matrix, string start, string end);
    State<string>* getInitialState();
    unordered_map<string, State<string>*> getMap();
    bool isGoalState(State<string>* obj);
    vector<State<string>*> getAllPossibleStates(State<string>* obj);
    ~Matrix();
};


#endif //MILESTONE_2_MATRIX_H
