//
// Created by HP on 30/09/2025.
//

#include "../includes/RecursiveDigitSum.h"

RecursiveDigitSum::RecursiveDigitSum() {
    cout << "Initialize Recursive Digit Sum Problem\n";
}

RecursiveDigitSum::~RecursiveDigitSum() {
    cout << "Destroy Recursive Digit Sum Problem\n";
}



int RecursiveDigitSum::superDigit(const string& n, const int k) {

    vector<vector<int>> dp(10, vector<int>(10));

    function<void ()> initDP = [&]() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j <= i; j++) {
                int sum = i + j;
                if (sum >= 10)
                    dp[i][j] = dp[j][i] = dp[sum/10][sum%10];
                else
                    dp[i][j] = dp[j][i] = sum;
            }
        }
    };

    initDP();

    function<int (string)> sumDigit = [&](string num){

        if (num.size() == 1)
            return num[0] - '0';

        int digit = *(num.end()-1) - '0';
        num.erase(num.size()-1, 1);
        int tail = sumDigit(num);

        return dp[digit][tail];
    };

    int sum = 0;
    for (auto s : n)
        sum += s - '0';

    int temp = sumDigit(to_string(sum));
    return sumDigit(to_string(temp * k));
}

void RecursiveDigitSum::run() {
    ifstream reader("Datas/recursive_digit_sum.txt");
    ofstream writer("Records/recursive_digit_sum.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    string n;
    int k;
    reader >> n >> k;

    writer << superDigit(n, k);

}
