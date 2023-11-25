
n = int(input())
piles = []
for i in range(n):
    pile = list(map(int, input().split()))
    piles.append(pile[1:]) 
f = [[0 for j in range(n)] for i in range(n)]


for i in range(n):
    f[i][i] = max(piles[i][0], piles[i][-1])
for l in range(2, n + 1):
    for i in range(n - l + 1): 
        j = i + l - 1 
        f[i][j] = max(piles[i][0] + min(f[i + 1][j - 1], f[i + 2][j]), piles[j][-1] + min(f[i][j - 2], f[i + 1][j - 1]))


total = sum(sum(pile) for pile in piles) 
score = 2 * f[0][n - 1] - total 
print(score)
