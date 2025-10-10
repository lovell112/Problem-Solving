//
// Created by HP on 10/10/2025.
//

#include "../includes/KFactorization.h"

KFactorization::KFactorization() {
    cout << "Initialize K Factorization Problem\n";
}

KFactorization::~KFactorization() {
    cout << "Destroyed K Factorization Problem\n";
}

vector<long long> KFactorization::kFactorization(int n, const vector<int> &A) {

    map<long long, vector<long long>> mapping;

    function<vector<long long> (const long long)> dfs = [&](const long long number) ->vector<long long> {
        if (mapping.contains(number)) {
            return mapping[number];
        }

        if (number > n) {
            mapping[number] = vector<long long>();
            return mapping[number];
        }

        if (number == n)
            return vector<long long>{number};


        long long minimum = LONG_LONG_MAX;
        vector<long long> best;
        for (const auto item : A) {
            const long long next = number*item;
            auto local = dfs(next);

            if (local.empty())
                continue;

            long long sum = number;
            for (const auto factor : local) {
                sum += factor;
            }

            if (minimum > sum) {
                minimum = sum;
                best = {number};
                for (const auto factor : local) {
                    best.push_back(factor);
                }
            }
        }
        mapping[number] = best;
        return mapping[number];
    };

    auto answer = dfs(1);
    return answer.empty() ? vector<long long>{-1} : answer;
}


void KFactorization::run() {
    ifstream reader("Datas\\k_factorization.txt");
    ofstream writer("Records\\k_factorization.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    int n;
    size_t size;
    reader >> n >> size;

    vector<int> A(size);

    for (auto& item : A)
        reader >> item;

    const vector<long long> results = kFactorization(n, A);

    for (const auto& factor : results)
        writer << factor << " ";

}
