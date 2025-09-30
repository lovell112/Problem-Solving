//
// Created by HP on 26/09/2025.
//

#ifndef PROBLEMS_CROSSWORDPUZZLE_H
#define PROBLEMS_CROSSWORDPUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <sstream>
#include "../../Interface/IProblem.h"
using namespace std;

class CrosswordPuzzle : public IProblem {
    static vector<string> crosswordPuzzle(vector<string>, string);
public:
    CrosswordPuzzle();
    ~CrosswordPuzzle() override;
    void run() override;
};


#endif //PROBLEMS_CROSSWORDPUZZLE_H