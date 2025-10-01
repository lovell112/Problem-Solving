//
// Created by HP on 01/10/2025.
//

#ifndef PROBLEMS_TRIGONOMETRY_H
#define PROBLEMS_TRIGONOMETRY_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include <vector>
#include "../../Interface/IProblem.h"

using namespace std;


class Trigonometry : public IProblem {
    static long long factorial(int);
    static float sin(float, int, float);
    static float cos(float, int, float);
public:
    Trigonometry();
    ~Trigonometry() override;
    void run() override;
};


#endif //PROBLEMS_TRIGONOMETRY_H