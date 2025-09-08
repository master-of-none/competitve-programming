#include "header.h"
using namespace std;

int rob(vector<int>& nums) {
    unordered_map<int, int> memo;

    function<int(int, unordered_map<int, int>&)> dfs =
        [&](int n, unordered_map<int, int>& memo) -> int {
        if (n < 0) {
            return 0;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        int res = max(dfs(n - 1, memo), nums[n] + dfs(n - 2, memo));
        memo[n] = res;
        return res;
    };

    return dfs(nums.size() - 1, memo);
}