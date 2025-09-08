#include "header.h"
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ROW = grid.size();
    int COLS = grid[0].size();
    set<pair<int, int>> visited;
    int res = 0, area = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if (r < 0 or r >= ROW or c < 0 or c >= COLS or
            visited.find({r, c}) != visited.end() or grid[r][c] == 0) {
            return 0;
        }
        visited.insert({r, c});
        int area = 1;
        for (auto [dr, dc] : directions) {
            area += dfs(r + dr, c + dc);
        }
        return area;
    };

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 1 and visited.find({r, c}) == visited.end()) {
                area = dfs(r, c);
                res = max(res, area);
            }
        }
    }
    return res;
}