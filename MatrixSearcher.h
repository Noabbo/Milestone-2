//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_MATRIXSEARCHER_H
#define MILESTONE_2_MATRIXSEARCHER_H

#include <queue>
#include <list>
#include "Searcher.h"
#include "Matrix.h"
using namespace std;

class MatrixSearcher : public Searcher<string, unordered_map<string, double>> {
    vector<string> marked_cells;
    priority_queue<State<string>*> openList;
    unordered_map<string, double> costPath;
    int evaluatedNodes;
protected:
    State<string>* popOpenList();
public:
    MatrixSearcher();
    int OpenListSize();
    int getNumberOfNodesEvaluated();
    void addNodeEvaluated();
    priority_queue<State<string>*> getOpenList();
    vector<string> getPath();
    bool isMarked(State<string>* s);
    double getLinePos(State<string>* s);
    double getColPos(State<string>* s);
    virtual unordered_map<string, double> search(Matrix searchable) = 0;
    vector<string> tracePath(State<string>* current);
    unordered_map<string, double> getCostPath();
    void buildCostPath(vector<string> path, Matrix searchable);
};


#endif //MILESTONE_2_MATRIXSEARCHER_H
