//
// Created by noa on 18/01/2020.
//

#ifndef MILESTONE_2_STATE_H
#define MILESTONE_2_STATE_H

#include <string>
using namespace std;
template <class T> class State {
T state;
double cost;
State<T> cameFrom;
public:
    // constructor
    State (T s, double c) {
        this->state = s;
        this->cost = c;
        this->cameFrom = NULL;
    }
    // override of equals
    bool Equals(State<T> s) {
        return state.equals(s.state);
    }
    // getters
    T getState() {
        return this->state;
    }
    double getCost() {
        return this->cost;
    }
    T getFather() {
        return this->comeFrom();
    }
    // setter
    void setFather(State<T> s) {
        this->comeFrom() = s;
    }
    // destructor
    ~State() {
        if (this->cameFrom != NULL) {
            delete(this->cameFrom);
        }
        delete(this->state);
        delete(this);
    }
};

#endif //MILESTONE_2_STATE_H
