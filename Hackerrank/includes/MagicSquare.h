//
// Created by HP on 27/08/2025.
//

#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H
#include <bits/stdc++.h>
#include "../../Interface/IProblem.h"
using namespace std;



class MagicSquare : public IProblem {
    static vector<vector<vector<int>>> initMagicSquares(vector<vector<int>>);
    static int formingMagicSquare(vector<vector<int>>);
public:
    MagicSquare();
    ~MagicSquare() override;
    void run() override;
};



#endif //MAGICSQUARE_H
