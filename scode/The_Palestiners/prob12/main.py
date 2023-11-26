from collections import deque

def is_valid_move(x, y, visited, city, k):
    return 0 <= x < len(city) and 0 <= y < len(city[0]) and not visited[x][y] and city[x][y] == '.'

def min_strides(city, start, end, k):
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    queue = deque([(start[0]-1, start[1]-1, 0)])  # Adjusting for 0-based indexing
    visited = [[False for _ in range(len(city[0]))] for _ in range(len(city))]
    visited[start[0]-1][start[1]-1] = True

    while queue:
        x, y, strides = queue.popleft()

        if (x, y) == end:
            return strides

        for dx, dy in directions:
            for i in range(1, k + 1):
                new_x, new_y = x + i * dx, y + i * dy

                if is_valid_move(new_x, new_y, visited, city, k):
                    visited[new_x][new_y] = True
                    queue.append((new_x, new_y, strides + 1))

    return -1

# Read input
W, H, K = map(int, input().split())
city = [input().strip() for _ in range(H)]
x1, y1, x2, y2 = map(int, input().split())

# Calculate and print result
result = min_strides(city, (x1, y1), (x2, y2), K)
print(result)
