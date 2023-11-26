from collections import deque

def is_valid_move(x, y, W, H, grid):
    return 1 <= x <= H and 1 <= y <= W and grid[x-1][y-1] == '.'

def min_strides(W, H, K, grid, x1, y1, x2, y2):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Right, Down, Left, Up

    visited = set()
    queue = deque([(x1, y1, 0)])  # (x, y, strides)
    visited.add((x1, y1))

    while queue:
        x, y, strides = queue.popleft()

        if x == x2 and y == y2:
            return strides

        for dx, dy in directions:
            for step in range(1, K + 1):
                new_x, new_y = x + step * dx, y + step * dy

                if is_valid_move(new_x, new_y, W, H, grid) and (new_x, new_y) not in visited:
                    queue.append((new_x, new_y, strides + 1))
                    visited.add((new_x, new_y))

    return -1

# Input reading
W, H, K = map(int, input().split())
grid = [input().strip() for _ in range(H)]
x1, y1, x2, y2 = map(int, input().split())

# Output the result
result = min_strides(W, H, K, grid, x1, y1, x2, y2)
print(result)