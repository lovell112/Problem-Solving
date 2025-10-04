//
// Created by HP on 03/10/2025.
//

#include "../includes/PasswordCracker.h"

#include <functional>

#include "../includes/RecursiveDigitSum.h"

PasswordCracker::PasswordCracker() {
    cout << "Initialize Password Cracker Sum Problem\n";
}

PasswordCracker::~PasswordCracker() {
    cout << "Destroy Password Cracker Problem\n";
}
// ver 1
// string PasswordCracker::passwordCracker(const vector<string> &passwords, const string &loginAttempt) {
//
//     bool found = false;
//     int count = 0;
//     function<void (int, vector<string>&, string)> concatenate = [&](const int index, vector<string>& concat, string attempt) {
//         cout << passwords[index] << endl;
//         if (found || attempt.size() > loginAttempt.size())
//             return;
//
//         concat.push_back(passwords[index]);
//
//         if (attempt == loginAttempt) {
//             found = true;
//             return;
//         };
//
//         for (int i = 0; i < passwords.size(); i++) {
//             concatenate(i, concat, attempt + passwords[i]);
//         }
//
//         if (!found)
//             concat.erase(concat.begin() + (concat.size()-1));
//     };
//
//     vector<string> res;
//     for (int i = 0; i < passwords.size() && !found; i++) {
//         concatenate(i, res, passwords[i]);
//         count = 0;
//     }
//
//     if (res.empty())
//         return "WRONG PASSWORD";
//
//     string concat;
//     bool space = false;
//     for (const auto& pass : res) {
//         if (space)
//             concat += " ";
//         concat += pass;
//         space = true;
//     }
//
//     return concat;
// }

// ver 2
// string PasswordCracker::passwordCracker(const vector<string> &passwords, const string &loginAttempt) {
//     string copyLoginAttempt = loginAttempt;
//     map<string, bool> passwordMapping;
//     for (const auto& pass : passwords)
//         passwordMapping[pass] = true;
//
//     bool space = false;
//     function<void (map<string, bool>&, string&, string&, string)> matchPassword = [&](map<string, bool>& mapping, string& res, string& login, string arg) {
//
//         if (login.empty()) {
//             if (!arg.empty())
//                 res = "WRONG PASSWORD";
//             return;
//         }
//
//         login.erase(login.begin());
//
//         if (mapping.count(arg)) {
//             if (space)
//                 res += " ";
//             res += arg;
//             arg = "";
//             space = true;
//         }
//         if (!login.empty())
//             arg += string(1, *login.begin());
//         matchPassword(mapping, res, login, arg);
//     };
//
//     string res;
//     string c = string(1, *copyLoginAttempt.begin());
//     matchPassword(passwordMapping, res, copyLoginAttempt, c);
//
//     return res;
// }

string PasswordCracker::passwordCracker(const vector<string> &passwords, const string &loginAttempt) {

    vector<string> path;
    vector<int> memo(loginAttempt.size(), -1);

    function<bool (const size_t)> isMatch;
    isMatch = [&](const size_t pos) -> bool {
        if (pos == loginAttempt.size())
            return true;
        if (memo[pos] == 0)
            return false;

        for (const auto &pw: passwords) {
            const size_t mov = pw.size();

            if (pos + mov <= loginAttempt.size()) {
                bool match = true;

                for (int i = 0; i < mov; i++) {
                    if (loginAttempt[pos + i] != pw[i]) {
                        match = false;
                        break;
                    }
                }

                if (!match)
                    continue;

                path.push_back(pw);
                if (isMatch(pos + mov)) {
                    memo[pos] = 1;
                    return true;
                }
                path.pop_back();
            }
        }

        memo[pos] = 0;
        return false;
    };

    if (!isMatch(0))
        return "WRONG PASSWORD";

    string res;
    bool space = false;
    for (const auto& p : path) {
        if (space)
            res += " ";
        res += p;
        space = true;
    }

    return res;
}

void PasswordCracker::run() {
    ifstream reader("Datas/password_cracker.txt");
    ofstream writer("Records/password_cracker.txt");

    if (!reader.is_open())
        cerr << "The path of the input file is not valid\n";
    else
        cout << "Connection to the input file was successfully\n";

    if (!writer.is_open())
        cerr << "The path of the output file is not valid\n";
    else
        cout << "Connection to the output file was successfully\n";

    int testcase;
    reader >> testcase;

    while (testcase--) {

        int numOfPass;
        reader >> numOfPass;

        vector<string> passwords(numOfPass);
        for (auto& pass : passwords)
            reader >> pass;

        string loginAttempt;
        reader >> loginAttempt;

        writer << passwordCracker(passwords, loginAttempt) << endl;

    }
}