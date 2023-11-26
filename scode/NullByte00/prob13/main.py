import math
n = int(input())
l = [int(i) for i in input().split()]
# l = [3, 3, 1]

subsets = []
def dfs(l, progress, subset):
    gcd = math.gcd(*subset)
    if len(subset) >= 2 and gcd <=1:
        return
    if(progress >= len(l)):
        if gcd > 1:
            subsets.append((subset, gcd))
        return
    dfs(l, progress+1, subset+[l[progress]])
    dfs(l, progress+1, subset)
    
dfs(l, 0, [])
# print(subsets)

def calculate(subset):
    return subset[1] * len(subset[0])

somme= 0
for subset in subsets:
    somme+=(calculate(subset))
print(somme)