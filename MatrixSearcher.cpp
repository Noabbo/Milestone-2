//
// Created by noa on 19/01/2020.
//

#include "MatrixSearcher.h"

State<string>* MatrixSearcher::popOpenList() {
    this->evaluatedNodes++;
    State<string>* state = this->openList.top();
    this->openList.pop();
    return state;
}

int MatrixSearcher::OpenListSize() {
    return this->openList.size();
}

int MatrixSearcher::getNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}

void MatrixSearcher::addNodeEvaluated() {
    this->evaluatedNodes++;
}

priority_queue<State<string>*> MatrixSearcher::getOpenList() {
    return this->openList;
}

vector<string> MatrixSearcher::getPath() {
    return this->marked_cells;
}

bool MatrixSearcher::isMarked(State<string> *s) {
    vector<string>::iterator it;
    for (it = marked_cells.begin(); it != marked_cells.end(); ++it) {
        // s is marked
        if (!(*it).compare(s->getState())) {
            return true;
        }
    }
    return false;
}

double MatrixSearcher::getLinePos(State<string>* s) {
    auto it = s->getState().find(",");
    string temp = s->getState();
    return stod(temp.substr(0, it));
}

double MatrixSearcher::getColPos(State<string>* s) {
    auto it = s->getState().find(",");
    string temp = s->getState();
    return stod(temp.substr(it+1));
}

vector<string> MatrixSearcher::tracePath(State<string>* current) {
    State<string>* tmp = current;
    vector<string> path;
    list<string> tmpPath;
    // finding path from goal to start
    while (current != NULL) {
        tmpPath.push_front(current->getState());
        tmp = tmp->getFather();
    }
    // copy list to vector
    while (!tmpPath.empty()) {
        path.push_back(tmpPath.back());
        tmpPath.pop_back();
    }
    return path;
}

unordered_map<string, double> MatrixSearcher::getCostPath() {
    return this->costPath;
}

void MatrixSearcher::buildCostPath(vector<string> path, Searchable<string> *searchable) {
    vector<string>::iterator it;
    for (it = path.begin(); it != path.end(); ++it) {
        string name = *it;
        State<string>* state = searchable->getMap().at(name);
        // initialize pair with cell's cost
        this->costPath.emplace(make_pair(name, state->getCost()));
        auto tmpIt = searchable->getMap().begin();
        // add costs of previous cells
        while (it->compare(tmpIt->second->getState()) != 0) {
            this->costPath[name] += tmpIt->second->getCost();
            tmpIt++;
        }
    }
}