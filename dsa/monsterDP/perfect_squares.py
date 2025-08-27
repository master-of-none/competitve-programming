import math


class Solution:
    def numSquares(self, n: int) -> int:
        squares = []
        for i in range(1, int(math.sqrt(n))+1):
            squares.append(i * i)

        def dfs(remaining):
            if remaining < 0:
                return float('inf')

            if remaining == 0:
                return 0

            res = float('inf')
            for square in squares:
                res = min(res, dfs(remaining - square) + 1)

            return res

        return dfs(n)

    def numSquaresMemo(self, n: int) -> int:
        squares = []
        memo = {}

        for i in range(1, int(math.sqrt(n))+1):
            squares.append(i * i)

        def dfs(remaining, memo):
            if remaining < 0:
                return float('inf')

            if remaining == 0:
                return 0

            res = float('inf')

            if remaining in memo:
                return memo[remaining]

            for square in squares:
                res = min(res, dfs(remaining - square, memo) + 1)

                memo[remaining] = res

            return res

        return dfs(n, memo)
