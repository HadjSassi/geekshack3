def dijkstra(graph, start):
    n = len(graph)
    dist = [float('inf')] * n
    dist[start - 1] = 0
    visited = [False] * n

    for _ in range(n):
        current = -1
        for i in range(n):
            if not visited[i] and (current == -1 or dist[i] < dist[current]):
                current = i

        visited[current] = True

        for neighbor, weight in graph[current + 1]:
            if dist[current] + weight < dist[neighbor - 1]:
                dist[neighbor - 1] = dist[current] + weight

    return dist

def count_missile_shooters(n, roads, s, l):
    graph = {i: [] for i in range(1, n + 1)}

    for v, u, w in roads:
        graph[v].append((u, w))
        graph[u].append((v, w))

    distances = dijkstra(graph, s)
    shooters_count = sum(1 for distance in distances if distance == l)

    return shooters_count

n, m, s = map(int, input().split())
roads = [tuple(map(int, input().split())) for _ in range(m)]
l = int(input())

result = count_missile_shooters(n, roads, s, l)
print(result)