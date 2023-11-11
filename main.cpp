#include <iostream>
#include <vector>
#include "planner.hpp"
#include "flujo.hpp"
#include "Dijkstra.hpp"
#include "printer.hpp"

using namespace std;

int main () {
    //E1 Cableado de colonias. PRIMs alg
    cout << "PRIM'S MOST COST EFFECTIVE USE OF RESOURSES." << endl;
    // vector<vector<int>> ciudades = {
    //     {0, 16, 45, 32},
    //     {16, 0, 18, 0, 7},
    //     {45, 18, 0, 7},
    //     {32, 21, 7, 0}
    // };
    // vector<vector<int>> ciudades = {
    //     {0, 2, 0, 6, 0},
    //     {2, 0, 3, 8, 5},
    //     {0, 3, 0, 0, 7},
    //     {6, 8, 0, 0, 9},
    //     {0, 5, 7, 9, 0}
    // };

    vector<vector<int>> ciudades = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };
    int x = ciudades.size();

    Planner p(x, ciudades);
    Printer pr;
    p.primMST();
    pr.print(p);
    cout << '\n';
//E2 Ruta mas corta. Dijstra's alg
    cout << "DIJKSTR'S SHORTTEST ROUTE FROM A TO B." << endl;

    Dijkstra dijkstra(ciudades);
    int start = 0; // Starting node
    int end = 4; // Destination node
    cout << "Shortest distance from " << start << " to " << end << " is " << dijkstra.shortestPath(start, end) << endl;
    cout << '\n';

//E3 Flujos Maximos
    // cout << "MAX FLOW FROM A TO B." << endl;
    // // vector<vector<int>> flujos = {
    // //     {0, 48, 12, 18},
    // //     {52, 0, 42, 32},
    // //     {18, 46, 0, 56},
    // //     {24, 36, 52, 0}
    // // };
    // vector<vector<int>> flujos = {
    //     {0,2,0,1},
    //     {0,0,1,3},
    //     {0,0,0,0},
    //     {0,0,2,0}
    // };

    // int source = 0;
    // int sink = 2;

    // Flujo flujo(flujos);
    
    // // Find max flow from the source node to the sink node
    // int maxFlow = flujo.fordFulkerson(source, sink);
    // cout << "The maximum possible flow from node " << source << " to node " << sink << " is " << maxFlow << endl;


    // pr.printMaximumFlow(flujo.getFlow());

//E4


};

