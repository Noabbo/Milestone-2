//
// Created by noa on 20/01/2020.
//

#include "AstarAlgorithm.h"

unordered_map<string, double> AstarAlgorithm::search(Matrix searchable) {
    unordered_map<string, double> currentCost, cheapestCost, heuristicCost;
    auto cell = searchable.getInitialState();
    // initial state is also the goal state
    if (searchable.isGoalState(cell)) {
        return vector<string>();
    }
    this->getOpenList().push(cell);
    // initializing maps
    currentCost = initCostMap(searchable);
    cheapestCost = initCostMap(searchable);
    heuristicCost = initHeuristicCost(searchable);
    currentCost.at(cell.getState()) = heuristicCost.at(cell.getState());
    cheapestCost.at(cell.getState()) = 0;
    while (this->OpenListSize() > 0) {
        auto current = findMinOpenList(this->getOpenList());
        // reached goal
        if (searchable.isGoalState(current)) {
            MatrixSearcher::buildCostPath(MatrixSearcher::tracePath(current), searchable);
            return this->getCostPath();
        }
        popFromOpenList(current);
        // find neighbours to current
        vector<State<string>*> adjacents = searchable.getAllPossibleStates(current);
        vector<State<string>*>::iterator it;
        for (it = adjacents.begin(); it != adjacents.end(); ++it) {
            double tmpCheapCost = cheapestCost.at(current.getState()) + (*it)->getCost();
            if (tmpCheapCost < cheapestCost.at((*it)->getState())) {
                (*it)->setFather(*current);
                cheapestCost.at((*it)->getState()) = tmpCheapCost;
                currentCost.at((*it)->getState()) = cheapestCost.at((*it)->getState()) + heuristicCost.at((*it)->getState());
                if (!isCurrentInOpenList(this->getOpenList(), *it)) {
                    this->getOpenList().push(*it);
                }
            }
        }
    }
    throw "error - no path found";
}

unordered_map<string, double> AstarAlgorithm::initHeuristicCost(Matrix searchable) {
    unordered_map<string, double> costMap;
    double goalLinePos = this->getLinePos(searchable.getGoalState());
    double goalColPos = this->getColPos(searchable.getGoalState());
    unordered_map<string, State<string>*>::iterator it;
    //move on the map and find approximate cost of path from every vertex to goal
    for (it = searchable.getMap().begin(); it != searchable.getMap().end(); ++it) {
        double linePos = this->getLinePos(it->second);
        double colPos = this->getColPos(it->second);
        double h = sqrt(pow((goalLinePos-linePos), 2) + pow((goalColPos-colPos), 2));
        costMap.emplace(make_pair(it->first, h));
    }
    return costMap;
}

unordered_map<string, double> AstarAlgorithm::initCostMap(Matrix searchable) {
    unordered_map<string, double> cheapMap = nullptr;
    unordered_map<string, State<string>*>::iterator it;
    for (it = searchable.getMap().begin(); it != searchable.getMap().end(); ++it) {
        cheapMap.emplace(make_pair(it->first, -1));
    }
    return cheapMap;
}

State<string> *AstarAlgorithm::findMinOpenList(priority_queue<State<string>*> openList) {
    State<string>* it = NULL;
    while (!openList.empty()) {
        it = openList.top();
        openList.pop();
    }
    return it;
}

void AstarAlgorithm::popFromOpenList(State<string>* current) {
    priority_queue<State<string>*> tmp;
    while (!this->getOpenList().top()->Equals(current)) {
        auto item = this->getOpenList().top();
        this->getOpenList().pop();
        tmp.push(item);
    }
    // pop current
    this->getOpenList().pop();
    while (!tmp.empty()) {
        auto item = tmp.top();
        tmp.pop();
        this->getOpenList().push(item);
    }
}

bool AstarAlgorithm::isCurrentInOpenList(priority_queue<State<string>*> list, State<string> *current) {
    while (!list.empty()) {
        auto it = list.top();
        if (it->Equals(current)) {
            return true;
        }
        list.pop();
    }
    return false;
}
