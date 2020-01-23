//
// Created by noa on 23/01/2020.
//

#include "DFSAlgorithm.h"

unordered_map<string, double> DFSAlgorithm::search(Searchable<string>* searchable) {
    stack<State<string>*> openStack;
    // initialize marked map
    auto cell = searchable->getInitialState();
    // initial state is also the goal state
    if (searchable->isGoalState(cell)) {
        return vector<string>();
    }
    openStack.push(cell);
    while (openStack.size() > 0) {
        this->addNodeEvaluated();
        auto x = openStack.top();
        openStack.pop();
        // cell is unmarked
        if (this->getNumberOfNodesEvaluated() > this->getPath().size()) {
            this->getPath().push_back(x.getState());
        }
        // end of search
        if (searchable->isGoalState(x)) {
            MatrixSearcher::buildCostPath(MatrixSearcher::tracePath(x), searchable);
            return this->getCostPath();
        }
        // add neighbours to list
        vector<State<string>*> adjacents = searchable->getAllPossibleStates(x);
        vector<State<string>*>::iterator it;
        for (it = adjacents.begin(); it != adjacents.end(); ++it) {
            // next one is not a wall
            if (((*it)->getCost() != -1) && !this->isMarked((*it))) {
                (*it)->setFather(x);
                openStack.push(*it);
            }
        }
    }
    throw "error - no path found";
}