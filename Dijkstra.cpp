// Dijkstra.cpp
#include "Dijkstra.hpp"
using namespace std;

Dijkstra::Dijkstra(const vector<vector<int>>& graph) {
    adjMatrix = graph;
}

int Dijkstra::minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

int Dijkstra::shortestPath(int start, int end) {
    int V = adjMatrix.size(); //9
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    return dist[end];
}
