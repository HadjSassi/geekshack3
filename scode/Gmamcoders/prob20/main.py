def is_winner(grid, player):
   
    for row in grid:
        for i in range(len(row) - 3):
            if row[i:i+4] == [player] * 4:
                return True
    for col in range(len(grid[0])):
        for i in range(len(grid) - 3):
            if [grid[j][col] for j in range(i, i+4)] == [player] * 4:
                return True
    for i in range(len(grid) - 3):
        for j in range(len(grid[0]) - 3):
            if [grid[i+k][j+k] for k in range(4)] == [player] * 4:
                return True
    for i in range(3, len(grid)):
        for j in range(len(grid[0]) - 3):
            if [grid[i-k][j+k] for k in range(4)] == [player] * 4:
                return True
    return False
def connect4_winner(grid):
    if is_winner(grid, 1):
        return 1
    if is_winner(grid, 2):
        return 2
    return 0

