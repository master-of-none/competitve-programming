#include "header.h"
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
    int ROW = grid.size();
    int COLS = grid[0].size();
    set<pair<int, int>> pac, atl;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> res;

    function<void(int, int, set<pair<int, int>>&, int)> dfs =
        [&](int r, int c, set<pair<int, int>> &hashset, int prevHeight) {
            if (r < 0 or r >= ROW or c < 0 or c >= COLS or
                hashset.find({r, c}) != hashset.end() or
                grid[r][c] < prevHeight) {
                return;
            }
            hashset.insert({r, c});

            for (auto [dr, dc] : directions) {
                dfs(r + dr, c + dc, hashset, grid[r][c]);
            }
        };

    for (int c = 0; c < COLS; c++) {
        dfs(0, c, pac, grid[0][c]);
        dfs(ROW - 1, c, atl, grid[ROW - 1][c]);
    }

    for (int r = 0; r < ROW; r++) {
        dfs(r, 0, pac, grid[r][0]);
        dfs(r, COLS - 1, atl, grid[r][COLS - 1]);
    }

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if ((pac.find({r, c}) != pac.end()) and
                (atl.find({r, c}) != atl.end()))
                res.push_back({r, c});
        }
    }
    return res;
}