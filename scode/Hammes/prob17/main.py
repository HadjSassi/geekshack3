def count_strings(s):
    MOD = 1000000007
    n = len(s)

    # dp[i][j] represents the number of ways to obtain the prefix s[0:i+1] with the last two characters being s[i-1] and s[i],
    # where j = 0 if the last two characters are 't', and j = 1 if the last two characters are 'v'.
    dp = [[0, 0] for _ in range(n)]

    # Initialize the base case
    if s[0] == 't':
        dp[0][0] = 1
    elif s[0] == 'v':
        dp[0][1] = 1

    # Iterate through the string to fill in the DP table
    for i in range(1, n):
        if s[i] == 't':
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD
        elif s[i] == 'v':
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD

    # The answer is the sum of the last row of the DP table
    result = sum(dp[-1]) % MOD

    return result

# Example usage:
s = input().strip()
result = count_strings(s)
print(result)
