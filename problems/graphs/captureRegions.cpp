#include "header.h"
using namespace std;

void solve(vector<vector<char>>& board) {
    int ROW = board.size();
    int COLS = board[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    function<void(int r, int c)> dfs = [&](int r, int c) {
        if (r < 0 or r >= ROW or c < 0 or c >= COLS or board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';

        for (auto [dr, dc] : directions) {
            dfs(r + dr, c + dc);
        }
    };

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == 'O' and
                ((r == 0 || r == ROW - 1) or (c == 0 || c == COLS - 1))) {
                dfs(r, c);
            }
        }
    }

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == 'O') board[r][c] = 'X';
        }
    }

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == 'T') board[r][c] = 'O';
        }
    }
}