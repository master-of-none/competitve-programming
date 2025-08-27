class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        def dfs(r, c):
            if r == m - 1 and c == n - 1:
                return 1

            if r >= m or c >= n:
                return 0

            res = dfs(r+1, c) + dfs(r, c+1)

            return res

        return dfs(0, 0)

    """
    For below memoization, I have started from last and then reached the beginning.
    Similar can be done by starting from 0 and then reaching the last cell
    
    """

    def uniquePathsMemo(self, m: int, n: int) -> int:
        memo = {}

        def dfs(r, c, memo):
            if r == 0 and c == 0:
                return 1

            if r < 0 or c < 0:
                return 0

            if (r, c) in memo:
                return memo[(r, c)]

            res = dfs(r-1, c, memo) + dfs(r, c-1, memo)
            memo[(r, c)] = res

            return res

        return dfs(m-1, n-1, memo)
