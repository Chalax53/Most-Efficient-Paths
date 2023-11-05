#include <iostream>
#include <vector>
#include "planner.hpp"
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


};