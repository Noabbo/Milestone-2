//
// Created by noa on 18/01/2020.
//

#include "Matrix.h"
// constructor
Matrix::Matrix(vector<string> matrix, string start, string end) {
    this->entry = new State(start, stod(matrix.front()));
    int line = 0;
    int col = 0;
    auto it = matrix.begin();
    while (it != matrix.end()) {
        // emd of line
        if (*it == "") {
            line++;
            col = 0;
            it++;
            break;
        }
        if (!end.compare(*it)) {
            // end point
            this->exit = new State(end, stod(*it));
        }
        // add point to map
        string pos = line;
        pos += ",";
        pos += col;
        State *s = new State(pos, stod(*it));
        this->vertex_map.emplace(make_pair(pos, s));
        col++;
        it++;
    }
}

State<string>* Matrix::getInitialState() {
    return this->entry;
}

bool Matrix::isGoalState(State<string>* obj) {
    return obj.Equals(this->exit);
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
    adjacents.push_back(this->vertex_map.find(place1));
    adjacents.push_back(this->vertex_map.find(place2));
    adjacents.push_back(this->vertex_map.find(place3));
    adjacents.push_back(this->vertex_map.find(place4));
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
    while (!this->vertex_map.empty()) {
        auto s = this->vertex_map.erase(this->vertex_map.begin());
        delete(s->second);
    }
    delete(this);
}

unordered_map<string, State<string> *> Matrix::getMap() {
    return this->vertex_map;
}
