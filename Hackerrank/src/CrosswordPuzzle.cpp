//
// Created by HP on 26/09/2025.
//

#include "../includes/CrosswordPuzzle.h"

CrosswordPuzzle::CrosswordPuzzle() {
    cout << "Initialize Crossword Puzzle Problem\n";
}

CrosswordPuzzle::~CrosswordPuzzle() {
    cout << "Destroyed Crossword Puzzle Problem\n";
}

vector<string> CrosswordPuzzle::crosswordPuzzle(vector<string> crossword, string words) {
    stringstream ss(words);
    string temp;
    vector<string> listWords;
    while (getline(ss, temp, ';')) {
        listWords.push_back(temp);
    }

    function<void (vector<vector<pair<int, int>>>&)> roadRow;
    roadRow = [&](vector<vector<pair<int, int>>>& cellList) {
        for (int i = 0; i < crossword[0].size(); i++) {
            
        }
    };

    vector<vector<pair<int, int>>> roadList;
    return crossword;
}

void CrosswordPuzzle::run() {
    ifstream reader("Datas/crossword_puzzle.txt");
    ofstream writer("Records/crossword_puzzle.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    vector<string> crossword(10);
    string words;

    for (auto row : crossword)
        reader >> row;

    reader >> words;


    vector<string> filledCrosswordGrid = crosswordPuzzle(crossword, words);

    for (const auto& row : filledCrosswordGrid) {
        for (const auto col : row)
            writer << col;
        writer << endl;
    }
}
