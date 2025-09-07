#include "header.h"
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int ROW = grid.size();
    int COLS = grid[0].size();
    set<pair<int, int>> visited;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int res = 0;

    function<void(int, int)> dfs = [&](int r, int c) {
        if (r < 0 or r >= ROW or c < 0 or c >= COLS or
            visited.find({r, c}) != visited.end() or grid[r][c] == '0')
            return;

        visited.insert({r, c});
        for (auto [dr, dc] : directions) {
            dfs(r + dr, c + dc);
        }
    };
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1' and visited.find({i, j}) == visited.end()) {
                res++;
                dfs(i, j);
            }
        }
    }
    return res;
}