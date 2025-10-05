#include "Application/ProblemProcessor.h"
#include "PrefixSumArray/prefixSumArray.h"
#include "Hackerrank/includes/SalesByMatch.h"
#include "Hackerrank/includes/ClimbingTheLeaderboard.h"
#include "Hackerrank/includes/MagicSquare.h"
#include "Hackerrank/includes/RoadsAndLibraries.h"
#include "Hackerrank/includes/FrogInMaze.h"
#include "Hackerrank/includes/CrosswordPuzzle.h"
#include "Hackerrank/includes/ThePowerSum.h"
#include "Hackerrank/includes/RecursiveDigitSum.h"
#include "Hackerrank/includes/SimplifiedChessEngine.h"

#include <iostream>
#include <fstream>

#include "Hackerrank/includes/PasswordCracker.h"
#include "Upcoder/includes/Trigonometry.h"

using namespace std;

void runSumLeftToRight();
void runCalculateAreaRectangle();

int main() {

    // ProblemProcessor::process(new ClimbingTheLeaderboard());

    // ProblemProcessor::process(new MagicSquare());

    // ProblemProcessor::process(new RecursiveDigitSum());

    // ProblemProcessor::process(new RoadsAndLibraries());

    // ProblemProcessor::process(new ThePowerSum());

    // ProblemProcessor::process(new RecursiveDigitSum());

    ProblemProcessor::process(new SimplifiedChessEngine());

    // ProblemProcessor::process(new Trigonometry());

    // ProblemProcessor::process(new PasswordCracker());

    return 0;
}

#pragma region Sum of One-Dimension Array from left to right
void runSumLeftToRight() {

    ifstream reader("Datas\\prefixSum_OneDimension.txt");
    if (!reader.is_open())
        cerr << "Error Path\n";

    ofstream writer("Records\\prefixSum_OneDimension.txt");
    if (!writer.is_open())
        cerr << "Error output file path\n";

    int n;
    reader >> n;

    vector<int> array(n);
    for (int &item : array)
        reader >> item;

    vector<int> pre = prefixSumArray::oneDimension(array);
    bool isFirst = true;
    writer << "[";
    for (auto i : pre) {
        if (!isFirst)
            writer << ",";
        writer << i;
        isFirst = false;
    }
    writer << "]";
    writer << endl;
    int left, right;
    int total = 0;
    while (reader >> left >> right) {
        try {
            if (left < 0 || right >= pre.size())
                throw out_of_range("Input is invalid");
            if (left != 0)
                total = pre[right] - pre[left - 1];
            else
                total = pre[right];
            writer << "[" << left << "][" << right << "] : " << total << endl;
            writer.flush();
        } catch (const out_of_range &e) {
            cerr << "Error : " << e.what() << endl;
            break;
        }
    }
    reader.close();
    writer.close();
}
#pragma endregion

#pragma region Area of Retangle (Two-Dimension Array)
void runCalculateAreaRectangle() {
    ifstream reader("Datas\\prefixSum_TwoDimension.txt");
    ofstream writer("Records\\prefixSum_TwoDimension.csv");
    if (!reader.is_open()) {
        cerr << "Error input file path\n";
        return;
    }
    if (!writer.is_open()) {
        cerr << "Error output file path\n";
        return;
    }

    struct point {
        int x;
        int y;
        point(const int x, const int y) : x(x), y(y) {}
        point& operator=(const point arg) {
            this->x = arg.x;
            this->y = arg.y;
            return *this;
        }
    };

    int row, col;
    reader >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));

    for (vector<int> &i : matrix)
        for (int &j : i)
            reader >> j;

    vector<vector<int>> area = prefixSumArray::twoDimension(matrix);

    for (const auto &i : area) {
        bool isFirst = true;
        for (const auto j : i) {
            if (!isFirst)
                writer << ",";
            writer << j;
            isFirst = false;
        }
        writer << endl;
    }
    writer.flush();

    point secondQuadrant(0, 0);
    point fourthQuadrant(0, 0);

    int query = 0;
    while (reader >> secondQuadrant.x >> secondQuadrant.y >> fourthQuadrant.x >> fourthQuadrant.y) {

        int result;

        point firstQuadrant(fourthQuadrant.x, secondQuadrant.y);
        point thirdQuadrant(secondQuadrant.x, fourthQuadrant.y);

        result = area[fourthQuadrant.y][fourthQuadrant.x];
        if (thirdQuadrant.x - 1 >= 0)
            result -= area[thirdQuadrant.y][thirdQuadrant.x - 1];
        if (firstQuadrant.y - 1 >= 0)
            result -= area[firstQuadrant.y - 1][firstQuadrant.x];
        if (firstQuadrant.y - 1 >= 0 && thirdQuadrant.x - 1 >= 0)
            result += area[secondQuadrant.y - 1][secondQuadrant.x - 1];

        writer << "[" << secondQuadrant.x << "][" << secondQuadrant.y << "],[" << fourthQuadrant.x << "][" << fourthQuadrant.y << "]," << result << endl;
    }

    reader.close();
    writer.close();
}
#pragma endregion