#include "header.h"
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    function<int(int, unordered_map<int, int>&)> dfs =
        [&](int n, unordered_map<int, int>& memo) -> int {
        if (n <= 1) return cost[n];
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        int res = cost[n] + min(dfs(n - 1, memo), dfs(n - 2, memo));
        memo[n] = res;
        return res;
    };
    unordered_map<int, int> memo;
    return min(dfs(cost.size() - 1, memo), dfs(cost.size() - 2, memo));
}