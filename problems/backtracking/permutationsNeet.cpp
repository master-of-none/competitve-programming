#include "header.h"
using namespace std;

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> used(nums.size(),false);

    function<void(int)> dfs = [&](int start) {
        if (start == (int)nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];

            if (used[i]) continue;

            temp.push_back(c);
            used[i] = true;

            dfs(start + 1);

            temp.pop_back();
            used[i] = false;
        }
    };
    dfs(0);
    return res;
}