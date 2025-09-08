#include "header.h"
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int ROW = grid.size();
    int COLS = grid[0].size();
    int time = 0, fresh = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 1) {
                fresh++;
            }

            if (grid[r][c] == 2) {
                q.push({r, c});
            }
        }
    }

    while (!q.empty() and fresh > 0) {
        time++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> rowCoL = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int row = dr + rowCoL.first;
                int col = dc + rowCoL.second;

                if (row < 0 or row >= ROW or col < 0 or col >= COLS or
                    grid[row][col] != 1)
                    continue;

                grid[row][col] = 2;
                q.push({row, col});
                fresh--;
            }
        }
    }

    return fresh == 0 ? time : -1;
}