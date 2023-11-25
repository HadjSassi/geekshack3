from collections import deque

n_nodes, n_vertecies, start = map(int, input().split())


graph = {}

for _ in range(n_vertecies):
    src, dst, length = map(int, input().split())
    if src not in graph:
        graph[src] = []
    if dst not in graph:
        graph[dst] = []
    graph[src].append((dst,length))
    graph[dst].append((src,length))
    
max_cost = int(input())


def bfs(start, graph, max_cost):
    count = 0
    visited = []
    queue = deque()
    # visited[start] = 0
    queue.append((start, 0))
    visited.append((start, 0))
    
    while queue:
        for _ in range(len(queue)):
            curr, cost = queue.popleft()
            if cost > max_cost:
                continue
            if cost == max_cost and curr!=start:
                count+=1
                continue
            for node in graph[curr]:
                if node not in visited:
                    if cost < max_cost:
                        if cost + node[1] > max_cost:
                            count+=1
                    queue.append((node[0], cost + node[1]))
    return count
            
b = bfs(start, graph, max_cost)
print(b)  