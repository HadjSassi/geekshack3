dp = {}
def count_zeros(a):
    if a in dp:
        return dp[a]
    if a == 1:
        return 0
    if a == 2:
        return 1
    if a %2 == 0:
        res = 1 + count_zeros(a >> 1)
        dp[a] = res
        return res
    else:
        res = count_zeros(a >> 1)
        dp[a] = res
        return res
        
    return 0

a, b = [int(i) for i in input().split()]
count = 0

for i in range(a, b+1):
    if count_zeros(i) == 1:
        count+=1
        
print(count)
       