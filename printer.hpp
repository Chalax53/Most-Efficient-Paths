#pragma once
#include "planner.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Printer {
public:
    void print(Planner& matrix);
    void printMaximumFlow(const vector<vector<int>>& flow);
};