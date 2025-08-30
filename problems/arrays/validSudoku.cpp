#include "header.h"
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> squares;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char val = board[r][c];
            if (val == '.') {
                continue;
            }
            int index = (r / 3) * 3 + (c / 3);

            if (rows[r].count(val) or cols[c].count(val) or
                squares[index].count(val)) {
                return false;
            }
            rows[r].insert(val);
            cols[c].insert(val);
            squares[index].insert(val);
        }
    }
    return true;
}