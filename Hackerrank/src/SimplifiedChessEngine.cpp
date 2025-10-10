//
// Created by HP on 30/09/2025.
//

#include "../includes/SimplifiedChessEngine.h"

#include <atomic>

SimplifiedChessEngine::SimplifiedChessEngine() {
    cout << "Initialize Simplified Chess Engine Problem\n";
}

SimplifiedChessEngine::~SimplifiedChessEngine() {
    cout << "Destroyed Simplified Chess Engine Problem\n";
}

// string SimplifiedChessEngine::simplifiedChessEngine(vector<vector<char>>& whites, vector<vector<char>>& blacks, int moves) {
//     for (auto& b : blacks)
//         b[0] += 32;
//
//     string result;
//
//     #pragma  region define the move ways
//     vector<vector<cell>> moveTo(4);
//     // Queen
//     moveTo[0] = {
//         {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
//         {1, 0}, {1, 1}, {0, 1}, {-1, 1}
//     };
//     // Rook
//     moveTo[1] = {
//         {-1, 0}, {0, -1}, {1, 0}, {0, 1}
//     };
//     // Knight
//     moveTo[2] = {
//         {-2, -1}, {-1, -2}, {-2, 1}, {2, -1},
//         {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
//     };
//     // Bishop
//     moveTo[3] = {
//         {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
//     };
//     #pragma endregion
//
//     function<vector<cell> (char, cell)> generateMoves = [&](const char piece, const cell pos) -> vector<cell> {
//         vector<cell> res;
//         if (piece == 'Q' || piece == 'q') {
//             for (auto del : moveTo[0]) {
//
//                 res.push_back({pos.row + del.row, pos.col + del.col});
//             }
//         } else if (piece == 'R' || piece == 'r') {
//             for (auto del : moveTo[1])
//                 res.push_back({pos.row + del.row, pos.col + del.col});
//         } else if (piece == 'N' || piece == 'n') {
//             for (auto del : moveTo[2])
//                 res.push_back({pos.row + del.row, pos.col + del.col});
//         } else if (piece == 'B' || piece == 'b') {
//             for (auto del : moveTo[3])
//                 res.push_back({pos.row + del.row, pos.col + del.col});
//         } else {
//             cerr << "The piece is invalid\n";
//         }
//
//         return res;
//     };
//     function<void (vector<vector<char>>&, const vector<vector<char>>&, const vector<vector<char>>&)> generateBoard;
//     generateBoard = [&](vector<vector<char>>& board, const vector<vector<char>>& whitePieces, const vector<vector<char>>& blackPieces) {
//         for (auto white : whitePieces) {
//             const char piece = white[0];
//             const int col = white[1] - 'A';
//             const int row = white[2] - '1';
//
//             board[row][col] = piece;
//         }
//
//         for (auto black : blackPieces) {
//             const char piece = black[0];
//             const int col = black[1] - 'A';
//             const int row = black[2] - '1';
//
//             board[row][col] = piece;
//         }
//
//     };
//
//     function<void (const char, const cell)> applyMoves = [&](const char state, const cell pos) {
//
//     };
//
//     vector<vector<char>> board(4, vector<char>(4, '.'));
//     generateBoard(board, whites, blacks);
//
//     return result;
// }

// string SimplifiedChessEngine::simplifiedChessEngine(vector<vector<char> > &whites, vector<vector<char> > &blacks, int move) {
//
//
//     for (auto& black : blacks)
//         black[0] += 32;
//
//     map<char, pair<char, char>> board;
//     for (const auto& w : whites)
//         board[w[0]] = {w[1], w[2]};
//     for (const auto& b : blacks)
//         board[b[0]] = {b[1], b[2]};
//
//     function<bool (const vector<vector<char>>&)> checkQueen = [&](const vector<vector<char>>& args) {
//         for (const auto& piece : args)
//             if ((piece[0] == 'Q' || piece[0] == 'q') && piece[1] == 'x' && piece[2] == 'x')
//                 return false;
//
//         return true;
//     };
//
//     function<vector<pair<int, int>> (const vector<char>&)> generateMoves = [&](const vector<char>& piece) -> vector<pair<int, int>> {
//         vector<pair<int, int>> res;
//         if (piece[0] == 'Q' || piece[0] == 'q') {
//             vector<pair<int, int>> ways = {
//                 {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
//                 {1, 0}, {1, 1}, {0, 1}, {-1, 1}
//             };
//             for (const auto& loc : ways) {
//                 for (int i = 0; (piece[2] + loc.first * i >= '1') && (piece[2] + loc.first * i <= '4') &&
//                     (piece[1] + loc.second * i <= 'D') && (piece[1] + loc.second * i >= 'A'); i++) {
//                     res.push_back({piece[1] + loc.second * i, piece[2] + loc.first * i});
//                 }
//             }
//         } else if (piece[0] == 'R' || piece[0] == 'r') {
//             vector<pair<int, int>> ways = {
//                 {-1, 0}, {0, -1}, {1, 0}, {0, 1}
//             };
//             for (const auto& loc : ways) {
//                 for (int i = 0; (piece[2] + loc.first * i >= '1') && (piece[2] + loc.first * i <= '4') &&
//                     (piece[1] + loc.second * i <= 'D') && (piece[1] + loc.second * i >= 'A'); i++) {
//                     res.push_back({piece[1] + loc.second * i, piece[2] + loc.first * i});
//                 }
//             }
//         }if (piece[0] == 'N' || piece[0] == 'n') {
//             vector<pair<int, int>> ways = {
//                 {-2, -1}, {-1, -2}, {-2, 1}, {2, -1},
//                 {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
//             };
//             for (const auto& loc : ways) {
//                 if (piece[2] + loc.first >= '1' && piece[2] + loc.first <= '4' &&
//                     piece[1] + loc.second >= 'A' && piece[1] + loc.second <= 'D')
//                     res.push_back({piece[1] + loc.second, piece[2] + loc.first});
//             }
//         } else if (piece[0] == 'B' || piece[0] == 'b') {
//             vector<pair<int, int>> ways = {
//                 {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
//             };
//             for (const auto& loc : ways) {
//                 for (int i = 0; (piece[2] + loc.first * i >= '1') && (piece[2] + loc.first * i <= '4') &&
//                     (piece[1] + loc.second * i <= 'D') && (piece[1] + loc.second * i >= 'A'); i++) {
//                     res.push_back({piece[1] + loc.second * i, piece[2] + loc.first * i});
//                 }
//             }
//         }
//
//         return res;
//     };
//
//     function<bool (const vector<char>&)> isWhite = [&](const vector<char>& piece) {
//         if (piece[0] >= 'A' && piece[0] <= 'Z')
//             return true;
//         return false;
//     };
//
//     function<bool (vector<char>&, int)> isWin = [&](vector<char>& piece, const int m) -> bool {
//         if (!checkQueen(blacks)) {
//             if (isWhite(piece))
//                 return true;
//             return false;
//         }
//
//         if (m == 0) {
//             if (isWhite(piece))
//                 return false;
//             return true;
//         }
//
//
//         auto possibleMoves = generateMoves(piece);
//
//         for (const auto& mov : possibleMoves) {
//             if (isWhite(piece)) {
//
//                 if (mov.first == board['q'].first && mov.second == board['q'].second)
//                     return true;
//
//                 char tempCol = piece[1];
//                 char tempRow = piece[2];
//                 board[piece[0]] = {mov.first, mov.second};
//                 piece[1] = (char)mov.first;
//                 piece[2] = (char)mov.second;
//
//                 for (auto& black : blacks) {
//
//                     pair<char, char> temp({'x', 'x'});
//                     if (mov.first == black[1] && mov.second == black[2]) {
//                         temp.first = black[1];
//                         temp.second = black[2];
//                         board[black[0]] = {'x', 'x'};
//                         black[1] = 'x';
//                         black[2] = 'x';
//                     }
//
//                     if (!isWin(black, m-1))
//                         return true;
//
//                     if (temp.first != 'x' && temp.second != 'x') {
//                         board[black[0]] = {temp.first, temp.second};
//                         black[1] = temp.first;
//                         black[2] = temp.second;
//                     }
//                 }
//                 board[piece[0]] = {tempCol, tempRow};
//                 piece[1] = (char)tempCol;
//                 piece[2] = (char)tempRow;
//             } else {
//
//                 if (mov.first == board['Q'].first && mov.second == board['Q'].second)
//                     return true;
//
//                 char tempCol = piece[1];
//                 char tempRow = piece[2];
//                 board[piece[0]] = {mov.first, mov.second};
//                 piece[1] = (char)mov.first;
//                 piece[2] = (char)mov.second;
//
//                 for (auto& white : whites) {
//
//                     pair<char, char> temp({'x', 'x'});
//                     if (mov.first == white[1] && mov.second == white[2]) {
//                         temp.first = white[1];
//                         temp.second = white[2];
//                         board[white[0]] = {'x', 'x'};
//                         white[1] = 'x';
//                         white[2] = 'x';
//                     }
//
//                     if (isWin(white, m-1))
//                         return false;
//
//                     if (temp.first != 'x' && temp.second != 'x') {
//                         board[white[0]] = {temp.first, temp.second};
//                         white[1] = temp.first;
//                         white[2] = temp.second;
//                     }
//                 }
//                 board[piece[0]] = {tempCol, tempRow};
//                 piece[1] = (char)tempCol;
//                 piece[2] = (char)tempRow;
//             }
//         }
//
//         return false;
//     };
//
//     bool win = false;
//     for (auto& white : whites)
//         if (isWin(white, move))
//             win = true;
//
//     string result = win ? "YES" : "NO";
//
//     return result;
//
// }

// string SimplifiedChessEngine::simplifiedChessEngine(vector<vector<char> > &whites, vector<vector<char> > &blacks, int move) {
//     for (auto& black : blacks)
//         black[0] += 32;
//
//     function<bool ()> isBlackQueenDie = [&]() ->bool {
//         for (const auto& black : blacks)
//             if (black[0] == 'q' && black[1] == 'x' && black[2] == 'x')
//                 return true;
//         return false;
//     };
//
//     function<bool (const vector<char>&)> isWhite = [&](const vector<char>& piece) {
//         if (piece[0] >= 'A' && piece[0] <= 'Z')
//             return true;
//         return false;
//     };
//
//     function<vector<pair<char, char>>(const vector<char>&)> generateMoves =
//         [&](const vector<char>& piece) -> vector<pair<char, char>> {
//
//         vector<pair<char, char>> res;
//         bool isWhitePiece = isupper(piece[0]);
//
//         // Helper: check what's at a position
//         // Returns: 0=empty, 1=same color, 2=opponent
//         auto checkPosition = [&](char col, char row) -> int {
//             if (isWhitePiece) {
//                 // White piece checking
//                 for (const auto& w : whites) {
//                     if (w[1] == col && w[2] == row) return 1; // Same color
//                 }
//                 for (const auto& b : blacks) {
//                     if (b[1] == col && b[2] == row) return 2; // Opponent
//                 }
//             } else {
//                 // Black piece checking
//                 for (const auto& b : blacks) {
//                     if (b[1] == col && b[2] == row) return 1; // Same color
//                 }
//                 for (const auto& w : whites) {
//                     if (w[1] == col && w[2] == row) return 2; // Opponent
//                 }
//             }
//             return 0; // Empty
//         };
//
//         char col = piece[1];
//         char row = piece[2];
//         char type = toupper(piece[0]);
//
//         if (type == 'N') {
//             // KNIGHT - independent moves, no blocking between
//             vector<pair<int, int>> moves = {
//                 {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
//                 {2, -1}, {1, -2}, {2, 1}, {1, 2}
//             };
//
//             for (const auto& [dr, dc] : moves) {
//                 char newCol = col + dc;
//                 char newRow = row + dr;
//
//                 // Check bounds
//                 if (newCol >= 'A' && newCol <= 'D' &&
//                     newRow >= '1' && newRow <= '4') {
//
//                     int status = checkPosition(newCol, newRow);
//
//                     if (status != 1) {  // Not same color (empty or opponent)
//                         res.push_back({newCol, newRow});
//                     }
//                     // Continue to next move (NOT break!)
//                 }
//             }
//
//         } else {
//             // SLIDING PIECES (Q, R, B)
//             vector<pair<int, int>> directions;
//
//             if (type == 'Q') {
//                 directions = {
//                     {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
//                     {1, 0}, {1, 1}, {0, 1}, {-1, 1}
//                 };
//             } else if (type == 'R') {
//                 directions = {
//                     {-1, 0}, {0, -1}, {1, 0}, {0, 1}
//                 };
//             } else if (type == 'B') {
//                 directions = {
//                     {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
//                 };
//             }
//
//             for (const auto& [dr, dc] : directions) {
//                 // Slide in this direction
//                 for (int step = 1; step <= 4; step++) {
//                     char newCol = col + dc * step;
//                     char newRow = row + dr * step;
//
//                     // Check bounds
//                     if (newCol < 'A' || newCol > 'D' ||
//                         newRow < '1' || newRow > '4') {
//                         break;  // Out of board, stop this direction
//                     }
//
//                     int status = checkPosition(newCol, newRow);
//
//                     if (status == 1) {
//                         // Same color - blocked, can't move here
//                         break;  // Stop this direction
//                     }
//
//                     // Can move here (empty or opponent)
//                     res.push_back({newCol, newRow});
//
//                     if (status == 2) {
//                         // Opponent - can capture, then stop
//                         break;  // Stop this direction
//                     }
//
//                     // status == 0: empty, continue sliding
//                 }
//             }
//         }
//
//         return res;
//     };
//
//     function<bool (bool, int)> canWin = [&] (bool whiteTurn, int m) -> bool {
//         if (whiteTurn) {
//             if (m == 0)
//                 return false;
//
//             bool canBlackWin = false;
//             for (auto& white : whites) {
//                 auto moveWays = generateMoves(white);
//                 for (const auto& pos : moveWays) {
//                     pair<char, char> oldPos {white[1], white[2]};
//                     white[1] = pos.first;
//                     white[2] = pos.second;
//
//                     for (auto& black : blacks) {
//                         if (white[1] == black[1] && white[2] == black[2]) {
//                             black[1] = 'x';
//                             black[2] = 'x';
//                         }
//                     }
//
//                     canBlackWin = canWin(false, m-1);
//
//                     for (auto& black : blacks) {
//                         if (black[1] == 'x' && black[2] == 'x') {
//                             black[1] = white[1];
//                             black[2] = white[2];
//                         }
//                     }
//
//                     white[1] = oldPos.first;
//                     white[2] = oldPos.second;
//                 }
//             }
//             if (canBlackWin)
//                 return false;
//             return true;
//         } else {
//             if (m == 0) {
//                 if (isBlackQueenDie())
//                     return false;
//                 return true;
//             }
//
//             bool canWhiteWin = true;
//             for (auto& black : blacks) {
//
//                 auto moveWays = generateMoves(black);
//
//                 for (auto& pos : moveWays) {
//                     pair<char, char> temp {black[1], black[2]};
//                     black[1] = pos.first;
//                     black[2] = pos.second;
//
//                     for (auto& white : whites) {
//                         if (white[1] == black[1] && white[2] == black[2]) {
//                             white[1] = 'x';
//                             white[2] = 'x';
//                         }
//                     }
//
//                     canWhiteWin = canWin(true, m-1);
//
//                     for (auto& white : whites) {
//                         if (white[1] == 'x' && white[2] == 'x') {
//                             white[1] = black[1];
//                             white[2] = black[2];
//                         }
//                     }
//
//                     black[1] = temp.first;
//                     black[2] = temp.second;
//                 }
//
//             }
//
//             if (canWhiteWin)
//                 return false;
//             return true;
//
//         }
//     } ;
//
//     return canWin(true, move) ? "YES" : "NO";
// }

string SimplifiedChessEngine::simplifiedChessEngine(vector<vector<char>>& whites, vector<vector<char>>& blacks, int moves) {
    // Convert black pieces to lowercase
    for (auto& black : blacks) {
        black[0] = tolower(black[0]);
    }

    // NO MEMOIZATION!

    // Helper functions giữ nguyên...
    function<bool(const vector<char>&)> isWhite = [](const vector<char>& piece) -> bool {
        return isupper(piece[0]);
    };

    function<bool(char)> isQueenCaptured = [&](char queen) -> bool {
        if (queen == 'Q') {
            for (const auto& w : whites) {
                if (w[0] == 'Q' && w[1] != 'x') {
                    return false;
                }
            }
            return true;
        } else {
            for (const auto& b : blacks) {
                if (b[0] == 'q' && b[1] != 'x') {
                    return false;
                }
            }
            return true;
        }
    };

    function<vector<pair<char, char>>(const vector<char>&)> generateMoves =
        [&](const vector<char>& piece) -> vector<pair<char, char>> {

        vector<pair<char, char>> res;

        if (piece[1] == 'x') {
            return res; // Captured piece
        }

        bool isWhitePiece = isupper(piece[0]);

        // Helper: check what's at a position
        // Returns: 0=empty, 1=same color, 2=opponent
        auto checkPosition = [&](char col, char row) -> int {
            if (isWhitePiece) {
                for (const auto& w : whites) {
                    if (w[1] == col && w[2] == row) return 1;
                }
                for (const auto& b : blacks) {
                    if (b[1] == col && b[2] == row) return 2;
                }
            } else {
                for (const auto& b : blacks) {
                    if (b[1] == col && b[2] == row) return 1;
                }
                for (const auto& w : whites) {
                    if (w[1] == col && w[2] == row) return 2;
                }
            }
            return 0;
        };

        char col = piece[1];
        char row = piece[2];
        char type = toupper(piece[0]);

        if (type == 'N') {
            // KNIGHT - independent moves
            vector<pair<int, int>> knightMoves = {
                {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                {2, -1}, {1, -2}, {2, 1}, {1, 2}
            };

            for (const auto& [dr, dc] : knightMoves) {
                char newCol = col + dc;
                char newRow = row + dr;

                if (newCol >= 'A' && newCol <= 'D' &&
                    newRow >= '1' && newRow <= '4') {

                    int status = checkPosition(newCol, newRow);

                    if (status != 1) {
                        res.push_back({newCol, newRow});
                    }
                }
            }

        } else {
            // SLIDING PIECES (Q, R, B)
            vector<pair<int, int>> directions;

            if (type == 'Q') {
                directions = {
                    {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
                    {1, 0}, {1, 1}, {0, 1}, {-1, 1}
                };
            } else if (type == 'R') {
                directions = {
                    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
                };
            } else if (type == 'B') {
                directions = {
                    {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
                };
            }

            for (const auto& [dr, dc] : directions) {
                for (int step = 1; step <= 4; step++) {
                    char newCol = col + dc * step;
                    char newRow = row + dr * step;

                    if (newCol < 'A' || newCol > 'D' ||
                        newRow < '1' || newRow > '4') {
                        break;
                    }

                    int status = checkPosition(newCol, newRow);

                    if (status == 1) {
                        break;
                    }

                    res.push_back({newCol, newRow});

                    if (status == 2) {
                        break;
                    }
                }
            }
        }

        return res;
    };


    // Minimax WITHOUT memoization
    function<bool(int, bool)> minimax = [&](int m, bool isWhiteTurn) -> bool {
        // NO CACHE CHECK!

        // Base cases
        if (isQueenCaptured('q')) return true;
        if (isQueenCaptured('Q')) return false;
        if (m == 0) return !isWhiteTurn;

        if (isWhiteTurn) {
            // White's turn
            for (auto& whitePiece : whites) {
                if (whitePiece[1] == 'x') continue;

                auto possibleMoves = generateMoves(whitePiece);

                for (const auto& [newCol, newRow] : possibleMoves) {
                    // Save state
                    char oldCol = whitePiece[1];
                    char oldRow = whitePiece[2];
                    vector<char> capturedBlack;
                    int capturedIdx = -1;

                    // Make move
                    whitePiece[1] = newCol;
                    whitePiece[2] = newRow;

                    for (int i = 0; i < blacks.size(); i++) {
                        if (blacks[i][1] == newCol && blacks[i][2] == newRow) {
                            capturedBlack = blacks[i];
                            capturedIdx = i;
                            blacks[i][1] = blacks[i][2] = 'x';
                            break;
                        }
                    }

                    // Recurse - WILL RECALCULATE SAME STATES!
                    bool blackCanDefend = minimax(m - 1, false);

                    // Unmake move
                    whitePiece[1] = oldCol;
                    whitePiece[2] = oldRow;
                    if (capturedIdx != -1) {
                        blacks[capturedIdx] = capturedBlack;
                    }

                    if (!blackCanDefend) {
                        return true;  // NO CACHE SAVE
                    }
                }
            }
            return false;

        } else {
            // Black's turn - similar logic
            for (auto& blackPiece : blacks) {
                if (blackPiece[1] == 'x') continue;

                auto possibleMoves = generateMoves(blackPiece);

                for (const auto& [newCol, newRow] : possibleMoves) {
                    char oldCol = blackPiece[1];
                    char oldRow = blackPiece[2];
                    vector<char> capturedWhite;
                    int capturedIdx = -1;

                    blackPiece[1] = newCol;
                    blackPiece[2] = newRow;

                    for (int i = 0; i < whites.size(); i++) {
                        if (whites[i][1] == newCol && whites[i][2] == newRow) {
                            capturedWhite = whites[i];
                            capturedIdx = i;
                            whites[i][1] = whites[i][2] = 'x';
                            break;
                        }
                    }

                    bool whiteCanWin = minimax(m - 1, true);

                    blackPiece[1] = oldCol;
                    blackPiece[2] = oldRow;
                    if (capturedIdx != -1) {
                        whites[capturedIdx] = capturedWhite;
                    }

                    if (!whiteCanWin) {
                        return false;
                    }
                }
            }
            return true;
        }
    };

    bool whiteWins = minimax(moves, true);
    return whiteWins ? "YES" : "NO";
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