from collections import deque
from math import ceil


def possiblePath(x, y,x1,y1, n, m, grid):
    if grid[x-1][y-1] == '*' or grid[x1 - 1][y1 - 1] == '*':
        return -1
    q = deque()
    q.append((x-1, y-1))
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    dis = [[-1 for _ in range(m)] for _ in range(n)]
    dis[x-1][y-1] = 0
    while q:
        p = q.popleft()
        for i in range(4):
            x = p[0] + dx[i]
            y = p[1] + dy[i]
            if 0 <= x < n and 0 <= y < m and dis[x][y] == -1:
                if grid[x][y] == '.':
                    dis[x][y] = dis[p[0]][p[1]] + 1
                    q.append((x, y))

    return dis[x1 - 1][y1 - 1]


n, m, k = list(map(lambda x: int(x), input().split()))
x, y, x1, y1 = list(map(lambda x: int(x), input().split()))
l = []
for i in range(n):
    l.append([*input()])
result = possiblePath(x, y, x1, y1,n,m, l)
if result != -1:
    print(ceil(result/k))
else:
    print(result)
 