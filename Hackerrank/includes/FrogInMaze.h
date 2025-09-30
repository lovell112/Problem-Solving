//
// Created by HP on 14/09/2025.
//

#ifndef FROGINMAZE_H
#define FROGINMAZE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include "../../Interface/IProblem.h"
using namespace std;

struct Cell {
    int row;
    int col;
    Cell(int, int);
};

using Matrix = vector<vector<char>>;
using Table = vector<vector<Cell>>;
using Couple = pair<int, int>;

class FrogInMaze : IProblem {
    static float probabilityEscape(const Matrix&, const Table&, const Cell&);
public:
    FrogInMaze();
    ~FrogInMaze() override;
    void run() override;
};





#endif //FROGINMAZE_H
