/* @JUDGE_ID: 1709779 12187 C++ "Brothers"*/

//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <vector>
using namespace std;

void battle(vector<vector<int>>& grid, int R, int C, int N) {
    vector<vector<int>> newGrid = grid;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int cur = grid[r][c];
            int enemy = (cur + 1) % N;

            for (size_t k = 0; k < directions.size(); k++) {
                int dr = directions[k].first;
                int dc = directions[k].second;

                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (grid[nr][nc] == enemy) newGrid[nr][nc] = cur;
                }
            }
        }
    }
    grid = newGrid;
}

int main() {
    while (1) {
        int N, R, C, K;
        cin >> N >> R >> C >> K;

        if (N == 0 && R == 0 && C == 0 && K == 0) break;

        vector<vector<int>> grid(R, vector<int>(C));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> grid[r][c];
            }
        }

        for (int i = 0; i < K; i++) {
            battle(grid, R, C, N);
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (c > 0) cout << " ";
                cout << grid[r][c];
            }
            cout << "\n";
        }
    }
    return 0;
}