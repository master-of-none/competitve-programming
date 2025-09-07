#include "header.h"
using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;

    function<void(int)> dfs = [&](int i) {
        if (i >= nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(i + 1);

        temp.pop_back();
        dfs(i + 1);
    };
    dfs(0);
    return res;
}
