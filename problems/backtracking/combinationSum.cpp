#include "header.h"
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;

    function<void(int, int)> dfs = [&](int i, int curSum) {
        if (i >= candidates.size() or curSum > target) {
            return;
        }
        if (curSum == target) {
            res.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        dfs(i, curSum + candidates[i]);

        temp.pop_back();
        dfs(i + 1, curSum);
    };
    dfs(0, 0);
    return res;
}