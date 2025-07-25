def fib_memo(n, memo):
    if n == 0 or n == 1:
        return n

    if n in memo:
        return memo[n]
    
    res = fib_memo(n-1, memo) + fib_memo(n-2, memo)
    memo[n] = res
    
    return res

def fib_iterative(n):
    dp = [0, 1]
    
    for i in range(2, n+1):
        dp.append(dp[i-1] + dp[i-2])
    
    return dp[-1]

if __name__ == "__main__":
    memo = {0:0}
    
    n = 10
    res = fib_memo(n, memo)
    print(f"Fibonacci value from memo is {res}")
    
    res = fib_iterative(n)
    print(f"Fibonacci value from iterative is {res}") 