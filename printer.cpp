#include "printer.hpp"

void Printer::print(Planner& matrix){
    vector<int>& parent = matrix.getParent();
    vector<vector<int>>& adjMatrix = matrix.getAdjMatrix();

    cout << "Vertice \tPeso" << endl;
for (int i = 1; i < static_cast<int>(parent.size()); i++) {
    cout << parent[i] << " - " << i << " \t\t" << adjMatrix[parent[i]][i] << "\n";
}

}

