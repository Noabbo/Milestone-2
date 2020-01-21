//
// Created by noa on 18/01/2020.
//

#include "BFSAlgorithm.h"

vector<string> BFSAlgorithm::search(Matrix searchable) {
    queue<State<string>*> openQueue;
    // initialize marked map
    auto cell = searchable.getInitialState();
    // initial state is also the goal state
    if (searchable.isGoalState(cell)) {
        return vector<string>();
    }
    openQueue.push(cell);
    while (openQueue.size() > 0) {
        this->addNodeEvaluated();
        auto x = openQueue.front();
        openQueue.pop();
        // cell is unmarked
        if (this->getNumberOfNodesEvaluated() > this->getPath().size()) {
            this->getPath().push_back(x.getState());
        }
        // end of search
        if (searchable.isGoalState(x)) {
            return MatrixSearcher::tracePath(x);
        }
        // add neighbours to list
        vector<State<string>*> adjacents = searchable.getAllPossibleStates(x);
        vector<State<string>*>::iterator it;
        for (it = adjacents.begin(); it != adjacents.end(); ++it) {
            // next one is not a wall
            if (((*it)->getCost() != -1) && !this->isMarked((*it))) {
                (*it)->setFather(x);
                openQueue.push(*it);
            }
        }
    }
    throw "error - no path found";
}
