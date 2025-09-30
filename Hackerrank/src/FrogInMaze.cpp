//
// Created by HP on 14/09/2025.
//

#include "../includes/FrogInMaze.h"

FrogInMaze::FrogInMaze() {
    cout << "Initialize Frog In Maze Problem\n";
}

FrogInMaze::~FrogInMaze() {
    cout << "Destroyed Frog In Maze Problem\n";
}

Cell::Cell(int row = -1, int col =  -1) : row(row), col(col) {}


float FrogInMaze::probabilityEscape(const Matrix & maze, const Table & tunnel, const Cell& begin) {
    float probability = 0.0f;

    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));


    char wall = '#';
    char mine = '*';
    char exit = '%';
    char free = '0';

    pair<int, int> neighborPosition[] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };
    function<void (const Matrix&, vector<vector<vector<Cell>>>&)> initGraph = [&](const Matrix& argMaze, vector<vector<vector<Cell>>>& graph) {
        graph.resize(argMaze.size(), vector<vector<Cell>>(argMaze[0].size()));
        for (int i = 0; i < argMaze.size(); i++) {
            for (int j = 0; j < argMaze[i].size(); j++) {
                vector<Cell> temp;
                for (const auto& neigh : neighborPosition) {
                    int row = i + neigh.first;
                    int col = j + neigh.second;

                    if (col >= 0 && col < argMaze[i].size() && row >= 0 && row < argMaze.size() && argMaze[row][col] != wall) {
                        if (tunnel[row][col].row != -1 && tunnel[row][col].col != -1) {
                            row = tunnel[row][col].row;
                            col = tunnel[row][col].col;
                        }
                        Cell cell(row, col);
                        temp.push_back(cell);
                    }
                }
                graph[i][j] = temp;
            }
        }
    };

    function<void(const Matrix&, const vector<vector<vector<Cell>>>&, const Cell&, float&)> calculateProbability = [&](const Matrix& maz, const vector<vector<vector<Cell>>>& graph, const Cell& alef, float& arg) {

        vector<vector<vector<int>>> p(graph.size(), vector<vector<int>>(graph[alef.row].size(), vector<int>(graph[alef.row][alef.col].size(),0)));

        // for (const auto& neighbor : graph[alef.row][alef.col]) {
        //     for ()
        // }
        //
        // arg += count / (1.0 * graph[alef.row][alef.col].size());

    };


    vector<vector<vector<Cell>>> graph;
    initGraph(maze, graph);
    calculateProbability(maze, graph, begin, probability);


    return probability;
}

void FrogInMaze::run() {

    ifstream reader("Datas/frog_in_maze.txt");
    ofstream writer("Records/frog_in_maze.txt");

    if (reader.is_open())
        cout << "Connected to the input file is successful\n";
    else
        cerr << "The input file is invalid\n";

    if (writer.is_open())
        cout << "Connected to the output file is successful\n";
    else
        cerr << "The output file is invalid\n";

    int n, m, k;
    reader >> n >> m >> k;

    Matrix maze(n, vector<char>(m));

    Cell Alef;
    for (int i = 0; i < maze.size(); i++)
        for (int j = 0; j < maze[i].size(); j++) {
            reader >> maze[i][j];
            if (maze[i][j] == 'A') {
                Alef.row = i;
                Alef.col = j;
            }
        }

    Cell temp(-1, -1);
    Table tunnel(n, vector<Cell>(m, temp));

    for (int i = 0; i < k; i++) {
        Cell pos_in;
        Cell pos_out;
        reader >> pos_in.row >> pos_in.col;
        reader >> pos_out.row >> pos_out.col;
        pos_in.row--;
        pos_in.col--;
        pos_out.row--;
        pos_out.col--;
        tunnel[pos_in.row][pos_in.col] = pos_out;
        tunnel[pos_out.row][pos_out.col] = pos_in;
    }

    writer << FrogInMaze::probabilityEscape(maze, tunnel, Alef);

}
