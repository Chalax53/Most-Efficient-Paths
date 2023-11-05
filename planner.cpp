#include "planner.hpp"
#include <iostream>
#include <climits>

//constructor
Planner::Planner(int nodos, const vector<vector<int>>& matrix) {
    this->nodos = nodos; //global seter
    adjMatrix = matrix;
    selected = vector<bool>(nodos, false);
    minWeight = vector<int>(nodos, INT_MAX);
    parent = vector<int>(nodos, -1);
}

int Planner::findMinVertex() {
    int minVertex = -1;
    for (int i = 0; i < nodos; i++) {
        if (!selected[i] && (minVertex == -1 || minWeight[i] < minWeight[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}


void Planner::primMST() {
    minWeight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < nodos - 1; i++) {
        int minVertex = findMinVertex();
        selected[minVertex] = true;

        for (int j = 0; j < nodos; j++) {
            if (adjMatrix[minVertex][j] != 0 && !selected[j]) {
                if (adjMatrix[minVertex][j] < minWeight[j]) {
                    minWeight[j] = adjMatrix[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }

    }
}

vector<int>& Planner::getParent() {
    return parent;
}

vector<vector<int>>& Planner::getAdjMatrix() {
    return adjMatrix;
}