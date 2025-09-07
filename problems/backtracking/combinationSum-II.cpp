#include "header.h"
using namespace std;
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;

    function<void(int, int)> dfs = [&](int i, int curSum) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i and candidates[j] == candidates[j - 1]) {
                continue;
            }
            temp.push_back(candidates[j]);
            dfs(j + 1, candidates[j] + curSum);

            temp.pop_back();
        }
    };
    dfs(0, 0);
    return res;
}