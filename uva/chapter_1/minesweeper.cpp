/* @JUDGE_ID: 1709779 10189 C++ "ThreeN+1"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                           {0, 1},   {1, -1}, {1, 0},  {1, 1}};

vector<vector<int>> solveMinesweeper(vector<string> &field, int n, int m) {
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                result[i][j] = -1;

                for (const auto &[dx, dy] : directions) {
                    int nR = i + dx, nC = j + dy;

                    if (nR >= 0 && nR < n && nC >= 0 && nC < m &&
                        result[nR][nC] != -1) {
                        result[nR][nC]++;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    int n, m, count = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector<string> field(n);
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        vector<vector<int>> result = solveMinesweeper(field, n, m);
        if (count > 1) {
            cout << endl;
        }
        cout << "Field #" << count++ << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (result[i][j] == -1) {
                    cout << '*';
                } else {
                    cout << result[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}