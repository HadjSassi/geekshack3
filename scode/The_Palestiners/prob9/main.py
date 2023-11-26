from collections import defaultdict, deque

def count_missile_shooters(n, m, s, roads, l):
    graph = defaultdict(list)
    for road in roads:
        v, u, w = road
        graph[v].append((u, w))
        graph[u].append((v, w))

    def bfs(start, target_dist):
        visited = [False] * (n + 1)
        queue = deque([(start, 0)])
        count = 0

        while queue:
            current, dist = queue.popleft()

            if visited[current]:
                continue

            visited[current] = True

            if dist == target_dist:
                count += 1

            for neighbor, weight in graph[current]:
                if not visited[neighbor]:
                    queue.append((neighbor, dist + weight))

        return count

    result = bfs(s, l)
    print(result)



input_lines = input().split("\n")
n, m, s = map(int, input_lines[0].split())
roads = [list(map(int, line.split())) for line in input_lines[1:m+1]]
l = int(input_lines[m+1])
count_missile_shooters(n, m, s, roads, l)   
   