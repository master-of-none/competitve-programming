/* @JUDGE_ID: 1709779 12150 C++ "Pole Position"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    while (cin >> n and n != 0) {
        vector<int> grid(n, -1);
        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++) {
            int c, p;
            cin >> c >> p;
            cars[i] = {c, p};
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            auto [c, p] = cars[i];
            int start = i + p;
            if (start < 0 || start >= n || grid[start] != -1) {
                flag = false;
                break;
            }
            grid[start] = c;
        }
        if (!flag) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << grid[i];
            }
            cout << endl;
        }
    }
    return 0;
}