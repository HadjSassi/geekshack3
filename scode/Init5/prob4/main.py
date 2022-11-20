try:

    N = 10

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    vis = set()

    def dfs(i, j):
        ans = 1
        vis.add((i, j))
        for k in range(4):
            ni = i + dx[k]
            nj = j + dy[k]
            if(ni < 0 or ni >= N or nj < 0 or nj >= N): continue 
            if(grid[i][j] != grid[ni][nj]): continue
            if(ni, nj) in vis: continue
            ans += dfs(ni, nj)

        return ans

    v = {'S' : [], 'T' : []}

    grid = [['0' for j in range(N)] for i in range(N)]

    n = int(input())

    for i in range(n):
        x = input().split()
        m = len(x)
        for j in range(m):
            grid[i][j] = x[j]

    for i in range(N):
        for j in range(N):
            if not (i, j) in vis and grid[i][j] != '0':
                sz = dfs(i, j)
                v[grid[i][j]].append(sz * 100)

    v['S'].sort()
    v['T'].sort()

    print("S", end=" ")
    n = len(v['S'])
    for i in range(n):
        if i == n - 1:
            print(v['S'][i])
        else:
            print(v['S'][i], end =" ")

    print("T",end =" ")
    n = len(v['T'])
    for i in range(n):
        if i == n - 1:
            print(v['T'][i])
        else:
            print(v['T'][i], end =" ")

except:
    print("NO")    