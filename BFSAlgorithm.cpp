//
// Created by noa on 18/01/2020.
//

#include "BFSAlgorithm.h"

vector<string> BFSAlgorithm::search(Matrix searchable) {
    // initialize marked map
    auto cell = searchable.getInitialState();
    this->getOpenList().push(cell);
    while (!this->OpenListSize() > 0) {
        auto x = this->popOpenList();
        // cell is unmarked
        if (this->getNumberOfNodesEvaluated() > this->getPath().size()) {
            this->getPath().push_back(x.getState());
        }
        // end of search
        if (x->Equals(searchable.isGoalState())) {
            return this->getPath();
        }
        // add neighbours to list
        vector<State<string>*> adjacents = searchable.getAllPossibleStates(x);
        auto it = adjacents.begin();
        while (it != adjacents.end()) {
            // next one is not a wall
            if ((*it)->getCost() != -1) {
                this->getOpenList().push(*it);
            }
        }
    }
    return this->getPath();
}
