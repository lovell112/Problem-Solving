//
// Created by HP on 12/09/2025.
//

#ifndef ROADSANDLIBRARIES_H
#define ROADSANDLIBRARIES_H

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <functional>
#include "../../Interface/IProblem.h"
using namespace std;


class RoadsAndLibraries : public IProblem{
    static long roadsAndLibraries(int, int, int, vector<vector<int>>);
public:
    RoadsAndLibraries();
    ~RoadsAndLibraries() override;
    void run() override;
};



#endif //ROADSANDLIBRARIES_H
