//
// Created by HP on 05/10/2025.
//

#include "../includes/StoneDivision.h"

#include <functional>


StoneDivision::StoneDivision() {
    cout << "Initialize Stone Division Problem\n";
}

StoneDivision::~StoneDivision() {
    cout << "Destroyed Stone Division Problem\n";
}


long long StoneDivision::stoneDivision(const long long n, const vector<long long>& set) {

    map<long long, long long> mapping;

    function<long long (const long long)> brows = [&](long long number) ->long long {

        if (mapping.contains(number))
            return mapping[number];

        long long best = 0;
        for (const auto& item : set) {
            if (number % item == 0 && number != item) {
                long long sub = brows(item);
                best = max(best, 1 + number/item*sub);
            }
        }
        mapping[number] = best;
        return mapping[number];

    };

    return brows(n);
}


void StoneDivision::run() {

    ifstream reader("Datas\\stone_division.txt");
    ofstream writer("Records\\stone_division.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    long queries;
    reader >> queries;

    bool newline = false;
    while (queries--) {

        long long n;
        reader >> n;

        size_t m;
        reader >> m;

        vector<long long> set(m);
        for (auto& item : set)
            reader >> item;

        if (newline)
            writer << endl;
        writer << stoneDivision(n, set);
        newline = true;

    }

}
