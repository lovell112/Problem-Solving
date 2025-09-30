//
// Created by HP on 25/08/2025.
//

#ifndef SALESBYMATCH_H
#define SALESBYMATCH_H
#include <bits/stdc++.h>
#include "../../Interface/IProblem.h"

// There is a large pile of socks that must be paired by color. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
//
// Example
//
// n = 7
// ar = [1, 2, 1, 2, 1, 3, 2]
//
// There is one pair of color 1 and one of color 2. There are three odd socks left, one of each color. The number of pairs is 2.
//
// Function Description
//
// Complete the sockMerchant function in the editor below.
//
// sockMerchant has the following parameter(s):
//
// int n: the number of socks in the pile
// int ar[n]: the colors of each sock
// Returns
//
// int: the number of pairs

class SalesByMatch : public IProblem {
    static int sockMerchant(int n, const std::vector<int>& ar);
public:
    SalesByMatch();
    ~SalesByMatch() override;
    void run() override;
};



#endif //SALESBYMATCH_H
