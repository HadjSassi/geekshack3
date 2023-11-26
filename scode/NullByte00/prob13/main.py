import math
n = int(input())
l = [int(i) for i in input().split()]

subsets = []
dp = {}
def dfs(l, progress, subset, gcd=-1):
    key = tuple(subset)
    if key in dp:
        gcd = dp[key]
    else:
        gcd = math.gcd(*subset)
        dp[key] = gcd
    if len(subset) >= 2 and gcd ==1:
        return
    if(progress >= len(l)):
        if gcd > 1:
            subsets.append((subset, gcd))
        return
    if gcd == -1:
        dfs(l, progress+1, subset+[l[progress]], l[progress])
        dfs(l, progress+1, subset)
    else:
        dfs(l, progress+1, subset+[l[progress]], math.gcd(gcd, gcd%l[progress]))
        dfs(l, progress+1, subset, gcd)
        
    
dfs(l, 0, [])
# print(subsets)

def calculate(subset):
        return subset[1] * len(subset[0])

somme= 0
for subset in subsets:
    somme+=(calculate(subset))
print(somme)     