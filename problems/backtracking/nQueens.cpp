#include "header.h"
using namespace std;

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    unordered_set<int> cols, posDiag, negDiag;

    function<void(int)> dfs = [&](int r) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) or posDiag.count(r + c) or negDiag.count(r - c))
                continue;

            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            dfs(r + 1);
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    };
    dfs(0);
    return res;
}
