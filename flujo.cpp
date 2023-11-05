#include "flujo.hpp"

Flujo::Flujo(const vector<vector<int>>& capacityMatrix) : capacity(capacityMatrix), numVertices(capacityMatrix.size()) {
    flow = vector<vector<int>>(numVertices, vector<int>(numVertices, 0));
    parent.resize(numVertices);
}

bool Flujo::bfs(int source, int sink) {
    vector<bool> visited(numVertices, false);
    vector<int> queue;
    queue.push_back(source);
    visited[source] = true;
    parent[source] = -1;

    int u;
    while (!queue.empty()) {
        u = queue.front();
        queue.erase(queue.begin());

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                queue.push_back(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int Flujo::fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    
    while (bfs(source, sink)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

const vector<vector<int>>& Flujo::getFlow() const {
    return flow;
}
