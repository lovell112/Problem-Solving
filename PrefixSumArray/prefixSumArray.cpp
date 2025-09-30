//
// Created by HP on 18/08/2025.
//

#include "prefixSumArray.h"

vector<int> prefixSumArray::oneDimension(const vector<int> &args) {
    size_t sizeArray = args.size();

    vector<int> result;

    for (size_t i = 0; i < sizeArray; i++) {
        if (i != 0)
            result.push_back(result[i-1] + args[i]);
        else
            result.push_back(args[i]);
    }

    return result;
}

vector<vector<int> > prefixSumArray::twoDimension(const vector<vector<int> > &args) {
    size_t col = args[0].size();
    size_t row = args.size();

    vector<vector<int>> result(row, vector<int>(col));

    for (size_t i = 0; i < row; i++) {

        for (size_t j = 0; j < col; j++) {
            if (i == 0) {
                if (j != 0)
                    result[i][j] += result[i][j-1] + args[i][j];
                else
                    result[i][j] = args[i][j];
            } else if (j == 0) {
                result[i][j] += result[i-1][j] + args[i][j];
            } else {
                result[i][j] = result[i-1][j] + result[i][j-1] - result[i-1][j-1] + args[i][j];
            }
        }
    }

    return result;
}
