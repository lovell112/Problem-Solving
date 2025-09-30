//
// Created by HP on 25/08/2025.
//

#include "../includes/SalesByMatch.h"

SalesByMatch::SalesByMatch() {
    std::cout << "Initialize Sales By Match Problem\n";
}

SalesByMatch::~SalesByMatch() {
    std::cout << "Destroyed Sales By Match Problem\n";
}

int SalesByMatch::sockMerchant(int n, const std::vector<int>& ar) {
    int numberOfPair = 0;
    std::vector<int> countSocks(100, 0);
    for(int i = 0; i < n; i++){
        numberOfPair -= countSocks[ar[i]] / 2;
        countSocks[ar[i]]++;
        numberOfPair += countSocks[ar[i]] / 2;
    }
    return numberOfPair;
}

void SalesByMatch::run(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &i : arr)
        std::cin >> i;
    int result = sockMerchant(n, arr);
    std::cout << result;
}