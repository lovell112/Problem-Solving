//
// Created by HP on 24/09/2025.
//

#ifndef PROBLEMS_THEPOWERSUM_H
#define PROBLEMS_THEPOWERSUM_H

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <functional>
#include <cmath>
#include "../../Interface/IProblem.h"
using namespace std;

class ThePowerSum : public IProblem {
    static int powerSum(int, int);
public:
    ThePowerSum();
    ~ThePowerSum() override;
    void run() override;
};


#endif //PROBLEMS_THEPOWERSUM_H