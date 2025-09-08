#include "header.h"
using namespace std;
int climbStairs(int n) {
    unordered_map<int, int> memo;

    function<int(int, unordered_map<int, int>&)> dfs =
        [&](int n, unordered_map<int, int>& memo) -> int {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int res = dfs(n - 1, memo) + dfs(n - 2, memo);
        memo[n] = res;
        return res;
    };
    return dfs(n, memo);
}