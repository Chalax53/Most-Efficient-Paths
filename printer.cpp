#include "printer.hpp"
using namespace std;

void Printer::print(Planner& matrix){
    vector<int>& parent = matrix.getParent();
    vector<vector<int>>& adjMatrix = matrix.getAdjMatrix();

    cout << "Vertice \tPeso" << endl;
    for (int i = 1; i < static_cast<int>(parent.size()); i++) {
        cout << parent[i] << " - " << i << " \t\t" << adjMatrix[parent[i]][i] << "\n";
    }

}


void Printer::printMaximumFlow(const vector<vector<int>>& flow) {
    for (int i = 0; i < flow.size(); i++) {
        for (int j = 0; j < flow[i].size(); j++) {
            if (flow[i][j] > 0) {
                cout << "Max flow from " << i << " to " << j << " has been set to: " << flow[i][j] << endl;
            }
        }
    }
}
