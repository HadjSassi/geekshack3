def min_time_to_paint(n, layers):
    dp = [float('inf')] * (n + 1)
    dp[0] = 0

    for i in range(1, n + 1):
        for j in range(i):
            room_times = [layers[k][i - 1] for k in range(j, i)]
            dp[i] = min(dp[i], dp[j] + sum(room_times))

    return dp[n]

# Read input
n = int(input())
layers = [list(map(int, input().split())) for _ in range(n)]

# Transpose the 2D list to properly handle the layers
layers = list(map(list, zip(*layers)))

# Calculate and print the result
result = min_time_to_paint(n, layers)
print(result)
