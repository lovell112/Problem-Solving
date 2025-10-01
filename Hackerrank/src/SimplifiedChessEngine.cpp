//
// Created by HP on 30/09/2025.
//

#include "../includes/SimplifiedChessEngine.h"

SimplifiedChessEngine::SimplifiedChessEngine() {
    cout << "Initialize Simplified Chess Engine Problem\n";
}

SimplifiedChessEngine::~SimplifiedChessEngine() {
    cout << "Destroyed Simplified Chess Engine Problem\n";
}

string SimplifiedChessEngine::simplifiedChessEngine(vector<vector<char>>& whites, vector<vector<char>>& blacks, int moves) {
    for (auto& b : blacks)
        b[0] += 32;

    string result;

    #pragma  region define the move ways
    vector<vector<cell>> moveTo(4);
    moveTo[0] = {
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        {1, 0}, {1, 1}, {0, 1}, {-1, 1}
    };
    moveTo[1] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };
    moveTo[2] = {
        {-2, -1}, {-1, -2}, {-2, 1}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };
    moveTo[3] = {
        {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
    };
    #pragma endregion

    function<vector<cell> (char, cell)> generateMoves = [&](const char piece, const cell pos) -> vector<cell> {
        vector<cell> result;
        if (piece == 'Q' || piece == 'q') {
            for (auto del : moveTo[0]) {

                result.push_back({pos.row + del.row, pos.col + del.col});
            }
        } else if (piece == 'R' || piece == 'r') {
            for (auto del : moveTo[1])
                result.push_back({pos.row + del.row, pos.col + del.col});
        } else if (piece == 'N' || piece == 'n') {
            for (auto del : moveTo[2])
                result.push_back({pos.row + del.row, pos.col + del.col});
        } else if (piece == 'B' || piece == 'b') {
            for (auto del : moveTo[3])
                result.push_back({pos.row + del.row, pos.col + del.col});
        } else {
            cerr << "The piece is invalid\n";
        }

        return result;
    };
    function<void (vector<vector<char>>&, const vector<vector<char>>&, const vector<vector<char>>&)> generateBoard;
    generateBoard = [&](vector<vector<char>>& board, const vector<vector<char>>& whitePieces, const vector<vector<char>>& blackPieces) {
        for (auto white : whitePieces) {
            const char piece = white[0];
            const int col = white[1] - 'A';
            const int row = white[2] - '1';

            board[row][col] = piece;
        }

        for (auto black : blackPieces) {
            const char piece = black[0];
            const int col = black[1] - 'A';
            const int row = black[2] - '1';

            board[row][col] = piece;
        }

    };

    function<void (const char, const cell)> applyMoves = [&](const char state, const cell pos) {

    };

    vector<vector<char>> board(4, vector<char>(4, '.'));
    generateBoard(board, whites, blacks);

    return result;
}

void SimplifiedChessEngine::run() {
    ifstream reader("Datas/simplified_chess_engine.txt");
    ofstream writer("Records/simplified_chess_engine.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    int g;
    reader >> g;
    while (g--) {

        int w, b, m;
        reader >> w >> b >> m;

        vector<vector<char>> whites(w, vector<char>(3));
        vector<vector<char>> blacks(b, vector<char>(3));

        for (auto& row : whites)
            for (auto& col : row)
                reader >> col;

        for (auto& row : blacks)
            for (auto& col : row)
                reader >> col;

        writer << simplifiedChessEngine(whites, blacks, m) << endl;
    }
}