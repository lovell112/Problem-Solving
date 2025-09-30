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
using namespace std;

struct Cell {
    int row;
    int col;
    Cell(int, int);
};

using Matrix = vector<vector<char>>;
using Table = vector<vector<Cell>>;
using Couple = pair<int, int>;

class FrogInMaze {
    static float probabilityEscape(const Matrix&, const Table&, const Cell&);
public:
    static void run();
};





#endif //FROGINMAZE_H
