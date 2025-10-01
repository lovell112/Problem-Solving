//
// Created by HP on 30/09/2025.
//

#ifndef PROBLEMS_SIMPLIFIEDCHESSENGINE_H
#define PROBLEMS_SIMPLIFIEDCHESSENGINE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include "../../Interface/IProblem.h"
using namespace std;


class SimplifiedChessEngine : public IProblem {
    struct cell {
        int row;
        int col;
    };
    static string simplifiedChessEngine(vector<vector<char>>&, vector<vector<char>>&, int);
    void run() override;
public:
    SimplifiedChessEngine();
    ~SimplifiedChessEngine() override;
};


#endif //PROBLEMS_SIMPLIFIEDCHESSENGINE_H