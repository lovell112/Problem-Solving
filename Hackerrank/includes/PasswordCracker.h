//
// Created by HP on 03/10/2025.
//

#ifndef PROBLEMS_PASSWORDCRACKER_H
#define PROBLEMS_PASSWORDCRACKER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "../../InterFace/IProblem.h"
using namespace std;

class PasswordCracker : public IProblem {
    static string passwordCracker(const vector<string>&, const string&);
public:
    PasswordCracker();
    ~PasswordCracker() override;
    void run() override;
};


#endif //PROBLEMS_PASSWORDCRACKER_H