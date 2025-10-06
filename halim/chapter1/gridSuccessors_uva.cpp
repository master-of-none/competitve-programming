/* @JUDGE_ID: 1709779 11581 C++ "Grid Successors"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transform(const vector<vector<int>>& g) {
    vector<vector<int>> f(3, vector<int>(3, 0));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int sum = 0;
            for (size_t k = 0; k < directions.size(); k++) {
                int dr = directions[k].first, dc = directions[k].second;
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
                    sum += g[nr][nc];
                }
            }
            f[r][c] = sum % 2;
        }
    }
    return f;
}

int solve(vector<vector<int>>& g) {
    vector<vector<vector<int>>> seen;

    while (true) {
        auto it = find(seen.begin(), seen.end(), g);
        if (it != seen.end()) {
            int a = it - seen.begin();
            return (a == 0 ? -1 : a - 1);
        }
        seen.push_back(g);
        g = transform(g);
    }
}

int main() {
    int T;

    cin >> T;

    while (T) {
        while (cin.peek() == '\n') cin.get();

        vector<vector<int>> grid(3, vector<int>(3));

        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 3; j++) {
                grid[i][j] = s[j] - '0';
            }
        }
        cout << solve(grid) << "\n";
        T--;
    }
    return 0;
}