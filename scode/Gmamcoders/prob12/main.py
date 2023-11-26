def min_strides(W, H, K, city, x1, y1, x2, y2):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    visited = set()
    queue = deque([(x1, y1, 0)])
    visited.add((x1, y1))
    while queue:
        x, y, strides = queue.popleft()
        if x == x2 and y == y2:
            return strides
        for dx, dy in directions:
            for k in range(1, K + 1):
                new_x, new_y = x + dx * k, y + dy * k
                if 1 <= new_x <= H and 1 <= new_y <= W and (new_x, new_y) not in visited and city[new_ x - 1][new_y - 1] == '.':
                    queue.append((new_x, new_y, strides + 1))
                    visited.add((new_x, new_y))
                else: 
                    break
    return -1
W, H, K = map(int, input().split())
city = [input().strip() for _ in range(H)]
x1, y1, x2, y2 = map(int, input().split())
result = min_strides(W, H, K, city, x1, y1, x2, y2)
print(result)