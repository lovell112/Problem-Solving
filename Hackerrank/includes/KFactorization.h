//
// Created by HP on 10/10/2025.
//

#ifndef PROBLEMS_KFACTORIZATION_H
#define PROBLEMS_KFACTORIZATION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>

#include "../../InterFace/IProblem.h"
using namespace std;

class KFactorization : public IProblem {
    static vector<long long> kFactorization(int, const vector<int>&);
public:
    KFactorization();
    ~KFactorization() override;
    void run() override;
};


#endif //PROBLEMS_KFACTORIZATION_H