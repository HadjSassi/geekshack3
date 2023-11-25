from collections import deque


class Graph:
    def __init__(self, n):
        self.len = n
        self.edges = [[] for _ in range(n)]

    def append(self, a, b):
        self.edges[a].append(b)
        self.edges[b].append(a)

    def bfs(self, s):
        dist = [-1] * self.len
        q = deque()
        q.append(s)
        dist[s] = 0
        while q:
            p = q.popleft()
            for i in self.edges[p]:
                if dist[i] == -1:
                    dist[i] = dist[p] + 1
                    q.append(i)
        return dist


h, w, k = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
c = []
c.append("X" * (w + 2))
for _ in range(h):
    s = input()
    c.append("X" + s + "X")
c.append("X" * (w + 2))
dp = [[-1 for _ in range(w + 2)] for _ in range(h + 2)]
q = deque()
q.append((x1, y1))
dp[x1][y1] = 0
while q:
    x, y = q.popleft()
    dx, dy = 0, 1
    for _ in range(4):
        px, py = x, y
        for i in range(k):
            px += dx
            py += dy
            if c[px][py] == "X":
                break
            if dp[px][py] == -1:
                dp[px][py] = dp[x][y] + 1
                q.append((px, py))
            elif dp[px][py] <= dp[x][y]:
                break
        dx, dy = dy, -dx
print(dp[x2][y2])