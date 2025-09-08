#include "header.h"
using namespace std;

void islandsAndTreasure(vector<vector<int>> grid) {
    int ROW = grid.size();
    int COLS = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    function<void(int, int)> bfs = [&](int r, int c) {
        if (r < 0 or r >= ROW or c < 0 or c >= COLS or
            visited.find({r, c}) != visited.end() or grid[r][c] == -1) {
            return;
        }
        visited.insert({r, c});
        q.push({r, c});
    };

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 0) {
                q.push({r, c});
                visited.insert({r, c});
            }
        }
    }
    int res = 0;

    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
            pair<int, int> rowCol = q.front();
            q.pop();
            grid[rowCol.first][rowCol.second] = res;

            for (auto [dr, dc] : directions) {
                bfs(rowCol.first + dr, rowCol.second + dc);
            }
        }
        res++;
    }
}