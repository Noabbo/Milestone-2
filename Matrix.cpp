//
// Created by noa on 18/01/2020.
//

#include "Matrix.h"

Matrix::Matrix(fstream file) {

}

State<string>* Matrix::getInitialState() {
    return this->entry;
}

bool Matrix::isGoalState(State<string>* obj) {
    return obj->Equals(this->exit);
}

vector<State<string>> Matrix::getAllPossibleStates(State<string> obj) {
    return vector<State<string>>();
}
