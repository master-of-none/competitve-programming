/* @JUDGE_ID: 1709779 10071 C++ "Back To school"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
using namespace std;

int calculate(int v, int t) { return 2 * v * t; }

int main() {
    int v, t;
    while (cin >> v >> t) {
        int res = calculate(v, t);
        cout << res << "\n";
    }
}