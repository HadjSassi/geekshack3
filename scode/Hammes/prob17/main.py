
def count_strings(s):
    MOD = 1000000007
    n = len(s)

    # Initialize DP array
    dp = [0] * (n + 1)
    dp[0] = 1

    # Iterate through the string
    for i in range(1, n + 1):
        dp[i] = dp[i - 1]

        if i >= 2 and s[i - 2:i] == 'tt':
            dp[i] = (dp[i] + dp[i - 2]) % MOD

        if i >= 2 and s[i - 2:i] == 'vv':
            dp[i] = (dp[i] + dp[i - 2]) % MOD

    return dp[n]

# Example usage:
s = input()
result = count_strings(s)
print(result)