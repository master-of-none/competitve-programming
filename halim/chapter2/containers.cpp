/* @JUDGE_ID: 1709779 01062 C++ "Rails" */
//!
//! Solved By: Shrikrishna Bhat
//!
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int caseNo = 1;

    while (cin >> s && s != "end") {
        vector<char> stacks;

        for (char c : s) {
            bool placed = false;
            for (char& top : stacks) {
                if (top >= c) {
                    top = c;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                stacks.push_back(c);
            }
        }
        cout << "Case " << caseNo++ << ": " << stacks.size() << "\n";
    }
    return 0;
}