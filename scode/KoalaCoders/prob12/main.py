from collections import deque

def destination(W, H, K, city, start, end):
    d = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    def destValide(x, y):
        return 1 <= x <= H and 1 <= y <= W and city[x-1][y-1] == '.'

    visited = set()
    queue = deque([(start[0], start[1], 0)])

    while queue:
        x, y, strides = queue.popleft()

        if (x, y) == end:
            return strides

        for dx, dy in d:
            for k in range(1, K+1):
                new_x, new_y = x + k * dx, y + k * dy

                if destValide(new_x, new_y) and (new_x, new_y) not in visited:
                    visited.add((new_x, new_y))
                    queue.append((new_x, new_y, strides + 1))

    return -1

W, H, K = map(int, input().split())

x1, y1, x2, y2 = map(int, input().split())
city = [input().strip() for f in range(H)]
start = (x1, y1)
end = (x2, y2)

result = destination(W, H, K, city, start, end)
print(result)