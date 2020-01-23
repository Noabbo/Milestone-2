//
// Created by noa on 20/01/2020.
//

#include "BestFSAlgorithm.h"

unordered_map<string, double> BestFSAlgorithm::search(Matrix searchable) {
    unordered_map<string, double> costMap = initCostMap();
    auto cell = searchable.getInitialState();
    // initial state is also the goal state
    if (searchable.isGoalState(cell)) {
        return vector<string>();
    }
    this->getOpenList().push(cell);
    while (this->OpenListSize() > 0) {
        auto current = this->popOpenList();
        this->getPath().push_back(current.getState());
        // end of path
        if (current->Equals(searchable.isGoalState())) {
            MatrixSearcher::buildCostPath(MatrixSearcher::tracePath(current), searchable);
            return this->getCostPath();
        }
        vector<State<string>*> adjacents = searchable.getAllPossibleStates(current);
        vector<State<string>*>::iterator it;
        for (it = adjacents.begin(); it != adjacents.end(); ++it) {
            if ((!isCurrentInOpenList(this->getOpenList(), *it)) && (!this->isMarked(*it))) {
                (*it)->setFather(current);
                this->getOpenList().push(*it);
                this->getPath().push_back(*it);
                this->addNodeEvaluated();
                costMap.at((*it)->getState()) = (*it)->getCost() + current->getCost();
            }
        }
    }
    throw "error - no path found";
}

unordered_map<string, double> BestFSAlgorithm::initCostMap(Matrix searchable) {
    unordered_map<string, double> cheapMap = nullptr;
    unordered_map<string, State<string>*>::iterator it = searchable.getMap().begin();
    cheapMap.emplace(make_pair(it->first, it->second->getCost()));
    it++;
    for (it; it != searchable.getMap().end(); ++it) {
        cheapMap.emplace(make_pair(it->first, -1));
    }
    return cheapMap;
}

bool BestFSAlgorithm::isCurrentInOpenList(priority_queue<State<string> *> list, State<string> *current) {
    while (!list.empty()) {
        auto it = list.top();
        if (it->Equals(current)) {
            return true;
        }
        list.pop();
    }
    return false;
}
