class Solution:
    def climbStairs(self, n: int) -> int:
        def dfs(n):
            if n < 0:
                return 0

            if n == 0:
                return 1
            res = dfs(n - 1) + dfs(n - 2)

            return res

        return dfs(n)

    def climbStairsMemo(self, n: int) -> int:
        memo = {}

        def dfs(n, memo):
            if n < 0:
                return 0

            if n == 0:
                return 1

            if n in memo:
                return memo[n]

            res = dfs(n - 1, memo) + dfs(n-2, memo)
            memo[n] = res

            return res

        return dfs(n, memo)
