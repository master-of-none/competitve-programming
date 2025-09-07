#include "header.h"
using namespace std;

bool exist(vector<vector<char>> &board, string word) {
    int ROWS = board.size();
    int COLS = board[0].size();

    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    function<bool(int, int, int)> search = [&](int r, int c, int i) {
        if (i == word.size()) return true;

        if (r < 0 or r >= ROWS or c < 0 or c >= COLS or visited[r][c] or
            board[r][c] != word[i]) {
            return false;
        }
        visited[r][c] = true;
        for (auto [dr, dc] : directions) {
            if (search(r + dr, c + dc, i + 1)) return true;
        }
        visited[r][c] = false;
        return false;
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (search(i, j, 0)) return true;
        }
    }
    return false;
}