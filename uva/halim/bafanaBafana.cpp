/* @JUDGE_ID: 1709779 11805 C++ "Bafana Bafana"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int t = T;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;

        int res = (k + p) % n;
        if (res == 0) res = n;
        cout << "Case " << (T - t) << ": " << res << "\n";
    }
}