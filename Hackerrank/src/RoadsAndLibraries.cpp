//
// Created by HP on 12/09/2025.
//

#include "../includes/RoadsAndLibraries.h"

long RoadsAndLibraries::roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    vector<bool> visited(n+1, false);
    long minCost = 0;

    function<long (int, const vector<vector<int>>&, vector<bool>&)> travel = [&](int city, const vector<vector<int>>& cities, vector<bool>& visited) -> long {
        if (visited[city])
            return 0;

        visited[city] = true;
        long cost = 0;
        for (int i = 0; i < cities[city].size(); i++) {
            if (!visited[cities[city][i]])
                cost += c_road;
            cost += travel(cities[city][i], cities, visited);
        }

        return cost;
    };

    function<long (const vector<vector<int>>&, int)> localLibCost = [](const vector<vector<int>>& cities, int c_lib) {
        return c_lib * (cities.size()-1);
    };

    for (int city = 1; city < cities.size(); city++) {
        if (visited[city])
            continue;
        minCost += travel(city, cities, visited);
        minCost += c_lib;
    }

    minCost = min(minCost, localLibCost(cities, c_lib));
    return minCost;
}

void RoadsAndLibraries::run() {
    ifstream reader("Datas\\roads_and_libraries.txt");
    ofstream writer("Records\\roads_and_libraries.txt");

    if (!reader.is_open())
        cerr << "The input path is invalid\n";
    else
        cout << "The input file is connected\n";

    if (!writer.is_open())
        cerr << "The output path is invalid\n";
    else
        cout << "The output file is connected";

    int t;
    reader >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, c_lib, c_road;
        reader >> n >> m >> c_lib >> c_road;
        vector<vector<int>> cities(n+1);
        for (int j = 0; j < m; j++) {
            int u, v;
            reader >> u >> v;
            cities[u].push_back(v);
            cities[v].push_back(u);
        }

        writer << roadsAndLibraries(n, c_lib, c_road, cities) << endl;
    }
}