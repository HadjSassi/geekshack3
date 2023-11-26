def min_paint_time(layers, times):
    n = len(times[0])
    
    # Initialize a 2D list to store the minimum time to paint each layer for each room
    dp = [[0] * n for _ in range(layers)]
    
    # Fill in the dp array
    for i in range(layers):
        for j in range(n):
            # Base case: if it's the first layer, the minimum time is the time given for that layer
            if i == 0:
                dp[i][j] = times[i][j]
            else:
                # For subsequent layers, calculate the minimum time by adding the current layer's time
                # and the minimum time of the previous layer
                dp[i][j] = times[i][j] + min(dp[i - 1][(j + k) % n] for k in range(n))
    
    # The result is the minimum time to paint the last layer in any room
    return min(dp[-1])

# Input
n = int(input())
times = []
for _ in range(n):
    layer_times = list(map(int, input().split()))
    times.append(layer_times)

# Output
result = min_paint_time(n, times)
print(result)
