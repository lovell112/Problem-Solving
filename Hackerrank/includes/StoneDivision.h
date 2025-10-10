//
// Created by HP on 05/10/2025.
//

#ifndef PROBLEMS_STONEDIVISION_H
#define PROBLEMS_STONEDIVISION_H
#include "../../InterFace/IProblem.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;


class StoneDivision : public IProblem{
    static long long stoneDivision(const long long , const vector<long long>& );
public:
    StoneDivision();
    ~StoneDivision() override;
    void run() override;
};


#endif //PROBLEMS_STONEDIVISION_H