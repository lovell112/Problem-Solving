//
// Created by HP on 29/08/2025.
//

#include "../includes/ClimbingTheLeaderboard.h"

ClimbingTheLeaderboard::ClimbingTheLeaderboard() {
    cout << "Initialize Climbing The Leaderboard Problem\n";
}

ClimbingTheLeaderboard::~ClimbingTheLeaderboard() {
    cout << "Destroyed Climbing The Leaderboard Problem\n";
}


vector<int> ClimbingTheLeaderboard::climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> result;
    map<int,int> leaderboard;
    int order = 0;
    for (const auto& i : ranked) {
        if (!leaderboard.contains(i)) {
            leaderboard[i] = ++order;
            // cout << i << " : " << leaderboard[i] << endl;
        }
    }

    auto temp_ranked(ranked);
    ranges::sort(temp_ranked.begin(), temp_ranked.end());
    for (const auto& p : player) {
        auto finder = ranges::upper_bound(temp_ranked.begin(), temp_ranked.end(), p);
        if (finder == temp_ranked.end())
            result.push_back(1);
        else if (*finder > p)
            result.push_back(leaderboard[*finder]+1);
        else if (*finder == p)
            result.push_back(leaderboard[*finder]);
    }

    return result;
}

void ClimbingTheLeaderboard::run() {

    ifstream reader("cmake-build-debug\\Datas\\climbing_the_leaderboard.txt");
    ofstream writer("Records\\climbing_the_leaderboard.txt");
    if (!reader.is_open())
        cerr << "The input path is invalid\n";
    else
        cout << "Successful Datas\\climbing_the_leaderboard.txt\n";

    if (!writer.is_open())
        cerr << "The output path is invalid\n";
    else
        cout << "Successful Records\\climbing_the_leaderboard.txt\n";

    int n;
    reader >> n;
    vector<int> ranked(n);
    for (auto& i : ranked)
        reader >> i;

    int m;
    reader >> m;
    vector<int> player(m);
    for (auto& i : player)
        reader >> i;

    vector<int> answer = climbingLeaderboard(ranked, player);

    for (const auto& i : answer)
        writer << i << endl;
}