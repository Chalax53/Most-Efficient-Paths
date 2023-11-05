#include <vector>
#include <climits>
#include <cstring> // for memset

using namespace std;

class Flujo {
private:
    int numVertices;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;
    vector<int> parent;
    
    bool bfs(int source, int sink); // Breadth-first search to find augmenting path

public:
    Flujo(const vector<vector<int>>& capacityMatrix);
    int fordFulkerson(int source, int sink); // Main algorithm method
    const vector<vector<int>>& getFlow() const;
};