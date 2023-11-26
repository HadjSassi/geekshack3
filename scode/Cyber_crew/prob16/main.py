
n, m, s = map(int, input().split()) 
graph = [[] for i in range(n + 1)] 
for i in range(m):
    v, u, w = map(int, input().split()) 
    graph[v].append((u, w)) 
    graph[u].append((v, w)) 
l = int(input()) 
queue = [s] 
distance = [float('inf')] * (n + 1) 
distance[s] = 0 
while queue:
    u = queue.pop(0) 
    for v, w in graph[u]:
        if distance[v] == float('inf'):
            distance[v] = distance[u] + w 
            queue.append(v)


shooters = 0
for d in distance:
    if d == l: 
        shooters += 1
print(shooters)  