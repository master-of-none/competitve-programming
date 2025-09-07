#include "header.h"
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;

    function<void(int)> dfs = [&](int i) {
        res.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            if (j > i and nums[j] == nums[j - 1]) {
                continue;
            }
            temp.push_back(nums[j]);
            dfs(j + 1);

            temp.pop_back();
        }
    };
    dfs(0);
    return res;
}
