#pragma once
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

class Flujo {
private:
    int numVertices;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;
    vector<int> parent;
    
    bool bfs(int source, int sink); 

public:
    Flujo(const vector<vector<int>>& capacityMatrix);
    int fordFulkerson(int source, int sink);
    const vector<vector<int>>& getFlow() const;
};