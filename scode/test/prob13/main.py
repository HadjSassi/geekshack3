from heapq import *

n, m, s = map(int, input().split())
g = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    g[u].append((v, w))
    g[v].append((u, w))
l = int(input())
d = [10 ** 10] * (n + 1)
d[s] = 0
q = [(0, s)]
while q:
    t, u = heappop(q)
    if t == d[u]:
        for v, w in g[u]:
            if d[v] > t + w:
                d[v] = t + w
                heappush(q, (d[v], v))

k = 0
for u in range(1, n + 1):
    for v, w in g[u]:
        if d[u] < l and d[u] + w > l:
            k += 2 if (l - d[u]) + (l - d[v]) < w else 1 if (l - d[u]) + (l - d[v]) == w else 0
print((k >> 1) + d.count(l))
 