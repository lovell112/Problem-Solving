//
// Created by HP on 30/09/2025.
//

#ifndef PROBLEMS_RECURSIVEDIGITSUM_H
#define PROBLEMS_RECURSIVEDIGITSUM_H
#include <iostream>
#include <fstream>
#include <functional>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include "../../Interface/IProblem.h"
using namespace std;

class RecursiveDigitSum : public IProblem {
    static int superDigit(const string&, const int);
    void run() override;
public:
    RecursiveDigitSum();
    ~RecursiveDigitSum() override;
};


#endif //PROBLEMS_RECURSIVEDIGITSUM_H