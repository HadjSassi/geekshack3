import heapq

def dijkstra(graph, start, l):
    n = len(graph)
    distances = [float('inf')] * n
    distances[start - 1] = 0
    heap = [(0, start)]

    while heap:
        current_distance, current_vertex = heapq.heappop(heap)

        if current_distance > distances[current_vertex - 1]:
            continue

        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight
            if distance < distances[neighbor - 1]:
                distances[neighbor - 1] = distance
                heapq.heappush(heap, (distance, neighbor))

    return [i for i in distances if i == l or (i < l and (l - i) % 2 == 0)]

def main():
    n, m, s = map(int, input().split())
    graph = {i: [] for i in range(1, n + 1)}

    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))

    l = int(input())
    result = dijkstra(graph, s, l)

    print(len(result))

if __name__ == "__main__":
    main()
