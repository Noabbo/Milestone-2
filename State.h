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
    State (T s, State<T> origin) {
        this->state = s;
        this->cost = 0;
        this->cameFrom = origin;
    }
    bool Equals(State<T> s) {
        return state.equals(s.state);
    }
};

#endif //MILESTONE_2_STATE_H
