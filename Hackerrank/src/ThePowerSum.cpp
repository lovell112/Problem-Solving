#include "../includes/ThePowerSum.h"

#include <cstdint>
#include <numbers>

ThePowerSum::ThePowerSum() {
    cout << "Initialize The Power Sum Problem\n";
}

ThePowerSum::~ThePowerSum() {
    cout << "Destroyed The Power Sum Problem\n";
}

int ThePowerSum::powerSum(const int x, const int n) {

    function<int (const int, const int, const int)> calculateWays = [&](const int origin, const int degree, const int current) -> int {
        int power = (int) pow(current, degree);

        if (power > origin)
            return 0;
        if (power == origin)
            return 1;

        return calculateWays(origin - power, degree, current+1) + calculateWays(origin, degree, current + 1);
    };

    return calculateWays(x, n, 1);

}

void ThePowerSum::run() {
    ifstream reader("Datas/the_power_sum.txt");
    ofstream writer("Records/the_power_sum.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    int x;
    int deg;
    reader >> x >> deg;

    writer << powerSum(x, deg);
}