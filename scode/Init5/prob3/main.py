N = 10

grid = [[0 for j in range(N)] for i in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

vis = set()

def dfs(i, j):
    ans = 1
    vis.add((i, j))
    for k in range(4):
        ni = i + dx[k]
        nj = j + dy[k]
        if ni < 0 or ni >= N or nj < 0 or nj >= N:
            continue 
        if grid[ni][nj] == 0 or (ni, nj) in vis:
            continue 
        ans += dfs(ni, nj)
    return ans
    

try:
    n = int(input())
    for i in range(n):
        x = list(map(int, input().split()))
        for j in x:
            grid[i][j] = 1


    vals = []
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 1 and not (i, j) in vis:
                vals.append(dfs(i, j))


    vals.sort()
    for item in vals:
        print(item * 100)
        
except:
    print("NO")
 