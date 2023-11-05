#include <iostream>
#include <vector>
#include "planner.hpp"
#include "flujo.hpp"
#include "printer.hpp"

using namespace std;

int main () {

    vector<vector<int>> ciudades = {
        {0, 16, 45, 32},
        {16, 0, 18, 0, 7},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };
    // vector<vector<int>> ciudades = {
    //     {0, 2, 0, 6, 0},
    //     {2, 0, 3, 8, 5},
    //     {0, 3, 0, 0, 7},
    //     {6, 8, 0, 0, 9},
    //     {0, 5, 7, 9, 0}
    // };

    // vector<vector<int>> ciudades = {
    //     {0,4,0,0,0,0,0,8,0},
    //     {4,0,8,0,0,0,0,11,0},
    //     {0,8,0,7,0,4,0,0,2},
    //     {0,0,7,0,9,14,0,0,0},
    //     {0,0,0,9,0,10,0,0,0},
    //     {0,0,4,14,10,0,2,0,0},
    //     {0,0,0,0,0,2,0,1,6},
    //     {8,11,0,0,0,0,1,0,7},
    //     {0,0,2,0,0,0,6,7,0}
    // };
    int x = ciudades.size();

    Planner p(x, ciudades);
    Printer pr;
    p.primMST();
    pr.print(p);


    //E3
    vector<vector<int>> flujos = {
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };

    int source = 0;
    int sink = 3;

    Flujo flujo(flujos);
    
    // Find max flow from the source node to the sink node
    int maxFlow = flujo.fordFulkerson(source, sink);
    cout << "The maximum possible flow from node " << source << " to node " << sink << " is " << maxFlow << endl;


    pr.printMaximumFlow(flujo.getFlow());
};