#include "header.h"
using namespace std;

int rob1(vector<int>& nums) {
    unordered_map<int, int> memo;
    function<int(int)> dfs = [&](int n) -> int {
        if (n < 0) return 0;
        if (memo.find(n) != memo.end()) return memo[n];

        int res = max(dfs(n - 1), nums[n] + dfs(n - 2));
        memo[n] = res;
        return res;
    };
    return dfs(nums.size() - 1);
}

int rob2(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> first(nums.begin() + 1, nums.end());
    vector<int> second(nums.begin(), nums.end() - 1);
    return max(rob1(first), rob1(second));
}
