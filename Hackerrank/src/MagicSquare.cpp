#include "../includes/MagicSquare.h"
using Matrix = vector<vector<int>>;

MagicSquare::MagicSquare() {
    cout << "Initialize Magic Square Problem\n";
}

MagicSquare::~MagicSquare() {
    cout << "Destroyed Magic Square Problem\n";
}

vector<Matrix> MagicSquare::initMagicSquares(Matrix s){

    vector<Matrix> permutations;

    for (auto& i : s)
        for (auto j : i)
            j = 0;

    function<void(int&, int&)> swap = [&](int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    };

    function<void(const Matrix&, int&, int&)> convertIndex = [&](const Matrix& mat, int& i, int& j) {
        if (i < 0)
            i = mat.size() - 1;
        else if (i >= mat.size())
            i = 0;

        if (j < 0)
            j = mat.size() -1;
        else if (j >= mat.size())
            j = 0;
    };

    function<void(Matrix&, int, int)> move = [&](Matrix& mat, int i, int j) {

        int preVal = 0;
        while (true) {

            pair<int, int> topRight = {i - 1, j + 1};
            pair<int, int> bottom = {i + 1, j};
            convertIndex(mat, topRight.first, topRight.second);
            convertIndex(mat, bottom.first, bottom.second);

            mat[i][j] = preVal + 1;
            preVal = mat[i][j];

            if (mat[topRight.first][topRight.second] == 0) {
                i = topRight.first;
                j = topRight.second;
            } else if (mat[bottom.first][bottom.second] == 0) {
                i = bottom.first;
                j = bottom.second;
            } else {
                break;
            }
        }

    };
    move(s, 0, 1);
    permutations.push_back(s);
    for (int i = 0; i < 3; i++) {
        Matrix temp(s.size(), vector<int>(s[0].size(), 0));
        for (int j = 0; j < temp.size(); j++) {
            for (int k = 0; k < temp[0].size(); k++) {
                if (j == 0)
                    temp[j][k] = permutations[i][k][temp.size()-1];
                else if (k == 0)
                    temp[j][k] = permutations[i][0][temp.size()-1 - j];
                else if (j == temp.size()-1)
                    temp[j][k] = permutations[i][k][0];
                else if (k == temp.size()-1)
                    temp[j][k] = permutations[i][temp.size()-1][temp.size()-1 - j];
                else
                    temp[j][k] = permutations[i][j][k];
            }
        }
        permutations.push_back(temp);
    }

    int size = permutations.size();
    for (int i = 0; i < size; i++) {
        Matrix temp(permutations[0].size(), vector<int>(permutations[0][0].size(), 0));
        for (int j = 0; j < temp.size(); j++) {
            for (int k = 0; k < temp[0].size(); k++) {
                if (j == 0)
                    temp[j][k] = permutations[i][temp.size() - 1][k];
                else if (j == temp.size() - 1)
                    temp[j][k] = permutations[i][0][k];
                else
                    temp[j][k] = permutations[i][j][k];
            }
        }
        permutations.push_back(temp);
    }

    return permutations;
}

int MagicSquare::formingMagicSquare(vector<vector<int> > s) {
    Matrix temp(s.size(), vector<int>(s.size(),0));
    vector<Matrix> permutations = initMagicSquares(temp);

    int minCost = INT_MAX;
    for (const auto& permutation : permutations) {
        int localCost = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <s.size(); j++) {
                localCost += abs(s[i][j] - permutation[i][j]);
            }
        }
        // cout << localCost << endl;
        minCost = min(minCost, localCost);
    }

    return minCost;
}


void MagicSquare::run() {

    ifstream reader("D:\\ProgrammingTechniques\\Problems\\cmake-build-debug\\Datas\\magic_square.txt");
    ofstream writer("D:\\ProgrammingTechniques\\Problems\\cmake-build-debug\\Records\\magic_square.txt");
    if (!reader.is_open())
        cerr << "Error input path\n";
    if (!writer.is_open())
        cerr << "Error output path\n";

    int n;
    reader >> n;

    Matrix s(n, vector<int>(n));
    for (auto& i : s)
        for (auto& j : i)
            reader >> j;

    Matrix temp(n, vector<int>(n,0));
    vector<Matrix> v = initMagicSquares(temp);

    for (const auto &i : v) {
        for (auto j : i) {
            for (auto k : j)
                writer << k << " ";
            writer << endl;
        }
        writer << endl;
    }

    writer << formingMagicSquare(s);

    reader.close();
    writer.close();
}