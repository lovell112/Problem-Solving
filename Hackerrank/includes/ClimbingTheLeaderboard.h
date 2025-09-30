//
// Created by HP on 29/08/2025.
//

#ifndef CLIMBINGTHELEADERBOARD_H
#define CLIMBINGTHELEADERBOARD_H
#include <bits/stdc++.h>
#include "../../Interface/IProblem.h"
using namespace std;


class ClimbingTheLeaderboard : public IProblem{
    static vector<int> climbingLeaderboard(vector<int>, vector<int>);
public:
    ClimbingTheLeaderboard();
    ~ClimbingTheLeaderboard() override;
    void run() override;
};



#endif //CLIMBINGTHELEADERBOARD_H
