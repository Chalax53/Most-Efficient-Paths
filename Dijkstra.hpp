// Dijkstra.hpp
#pragma once
#include <vector>
#include <limits.h>

using namespace std;

class Dijkstra {
public:
    Dijkstra(const vector<vector<int> >& graph);
    int shortestPath(int start, int end);

private:
    vector<vector<int>> adjMatrix;
    int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V);
};
