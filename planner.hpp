#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Planner {

public:
    int nodos; 
    vector<vector<int> > adjMatrix;
    vector<bool> selected;
    vector<int> minWeight;
    vector<int> parent;
    int findMinVertex();


    Planner(int nodos, const vector<vector<int> >& matrix);
    void primMST();


    vector<int>& getParent();
    vector<vector<int>>& getAdjMatrix();
};