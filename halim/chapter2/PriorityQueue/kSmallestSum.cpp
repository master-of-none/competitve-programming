/* @JUDGE_ID: 1709779 11997 C++ "k Smallest Sum" */

//!
//! Solved By: Shrikrishna Bhat
//!

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge2Lists(const vector<int>& A, const vector<int>& B, int k) {
    vector<int> result;

    return result;
}

int main() {
    int k;
    while (cin >> k) {
        vector<vector<int>> lists(k, vector<int>(k));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> lists[i][j];
            }
            sort(lists[i].begin(), lists[i].end());
        }
        vector<int> result = lists[0];
        for (int i = 1; i < k; i++) {
            result = merge2Lists(result, lists[i], k);
        }

        for (int i = 0; i < k; i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }

    return 0;
}
