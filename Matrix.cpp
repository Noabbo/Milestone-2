//
// Created by noa on 18/01/2020.
//

#include "Matrix.h"
// constructor
Matrix::Matrix(vector<string> matrix, string start, string end) {
    this->entry = new State<string>(start, stod(matrix.front()));
    int line = 0;
    int col = 0;
    auto it = matrix.begin();
    int i = 0;
    while (it != matrix.end()) {
        i++;
        string l = *it;
        while (!l.empty()) {
            string cost;
            size_t comma = l.find(",");
            if (comma == string::npos) {
                cost = l;
            } else {
                cost = l.substr(0, comma);
            }
            // add point to map
            string pos = to_string(line);
            pos += ",";
            pos += to_string(col);

            State<string> *s = new State<string>(pos, stod(cost));
            this->getMap().emplace(make_pair(pos, s));
            if (!end.compare(pos)) {
                // end point
                this->exit = s;
            }
            col++;
            if (comma == string::npos) {
                l.clear();
            } else {
                l = l.substr(comma+1);
            }
        }
        // end of line
        line++;
        col = 0;
        it++;
    }
}

State<string>* Matrix::getInitialState() {
    return this->entry;
}

State<string>* Matrix::getGoalState() {
    return this->exit;
}

bool Matrix::isGoalState(State<string>* obj) {
    return this->exit->Equals(*obj);
}
// gets all neighbours of vertex in matrix
vector<State<string>*> Matrix::getAllPossibleStates(State<string>* obj) {
    vector<State<string>*> adjacents;
    string pos = obj->getState();
    auto divide = pos.find(",");
    string linePos = pos.substr(0, divide);
    string colPos = pos.substr(divide+1);
    // find and add adjacents to list
    string place1 = linePos;
    string place2 = linePos;
    string place3 = to_string(stoi(linePos)+1);
    string place4 = to_string(stoi(linePos)-1);
    place1 += ",";
    place2 += ",";
    place3 += ",";
    place4 += ",";
    place1 += to_string(stoi(colPos)+1);
    place2 += to_string(stoi(colPos)-1);
    place3 += colPos;
    place4 += colPos;
    adjacents.push_back(this->getMap().find(place1)->second);
    adjacents.push_back(this->getMap().find(place2)->second);
    adjacents.push_back(this->getMap().find(place3)->second);
    adjacents.push_back(this->getMap().find(place4)->second);
    return adjacents;
}
// destructor
Matrix::~Matrix() {
    if (this->entry != nullptr) {
        delete(this->entry);
    }
    if (this->exit != nullptr) {
        delete(this->exit);
    }
    while (!this->getMap().empty()) {
        auto s = this->getMap().erase(this->getMap().begin());
        delete(s->second);
    }
    delete(this);
}
