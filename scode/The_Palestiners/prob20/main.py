def check_winner(grid):
    def check_direction(x, y, dx, dy):
        color = grid[x][y]
        count = 0
        while 0 <= x < rows and 0 <= y < cols and grid[x][y] == color:
            count += 1
            x, y = x + dx, y + dy
        return count >= 4

    def check_all_directions(x, y):
        directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        for dx, dy in directions:
            if check_direction(x, y, dx, dy):
                return True
        return False

    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] != 0 and check_all_directions(i, j):
                return grid[i][j]

    return 0

def connect_four_winner(rows, cols, input_grid):
    grid = [list(map(int, row)) for row in input_grid]

    for i in range(rows - 1, -1, -1):
        for j in range(cols):
            if grid[i][j] == 0:
                if i == rows - 1 or grid[i + 1][j] != 0:
                    grid[i][j] = 1
                    winner = check_winner(grid)
                    if winner != 0:
                        return winner
    return 0

# Example usage:
rows, cols = map(int, input().split())
input_grid = [input() for _ in range(rows)]
result = connect_four_winner(rows, cols, input_grid)
print(result)
