//
// Created by HP on 01/10/2025.
//

#include "../includes/Trigonometry.h"

Trigonometry::Trigonometry() {
    cout << "Initialize Trigonometry Problem\n";
}

Trigonometry::~Trigonometry() {
    cout << "Destroyed Trigonometry Problem\n";
}

long long Trigonometry::factorial(const int n) {
    if (n <= 1)
        return 1L;

    const long long result = n * factorial(n-1);
    return result;
}


float Trigonometry::sin(const float x, const int n = 0, const float eps = 0.0001f) {

    float current = pow(-1, n)*(pow(x, 2*n+1)/factorial(2*n+1));

    if (fabs(current) < 0.0001)
        return 0;

    float next = sin(x, n+1);
    return current + next;
}

float Trigonometry::cos(const float x, const int n = 0, const float eps = 0.0001) {
    float current = pow(-1, n) * pow(x, 2*n) / factorial(2*n);

    if (fabs(current) < eps)
        return 0;

    float next = cos(x, n+1);
    return current + next;
}

void Trigonometry::run() {
    ifstream reader("Datas/trigonometry.txt");
    ofstream writer("Records/trigonometry.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    float x;
    reader >> x;

    writer << roundf(sin(x) * 100) / 100 << endl;
    writer << roundf(cos(x) * 100) / 100 << endl;
}