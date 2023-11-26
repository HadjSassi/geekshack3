from collections import deque

h, w, k= map(int,input().split())
x1, y1, x2, y2 = map(int,input().split())
x1, y1, x2, y2 = x1 -1 , y1 -1 , x2 -1 , y2 -1 
grid =[]
for i in range(h):
    grid.append(list(input()))

for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == ".":
            grid[i][j] = 0
        else:
            grid[i][j] = 1

neighbors = []  
for i in range(1,k+1):
    neighbors.append([0,i])
    neighbors.append([0,-i])
    neighbors.append([i,0])
    neighbors.append([-i,0])
# print(neighbors)

def not_valid(r, dr, c, dc):
    if dr == 0:
        if dc > 0:
            for i in range(c, c+dc):
                if grid[r][i] == 1:
                    return True 
        else:
            for i in range(c+dc, c):
                if grid[r][i] == 1:
                    return True 
    elif dc ==0:
        if dr>0:
            for i in range(r, r+dr):
                if grid[i][c] == 1:
                    return True 
        else:
            for i in range(r+dr, r):
                if grid[i][c] == 1:
                    return True 
            
    return False
    

# Shortest path from top left to bottom right
def bfs(grid):
    ROWS, COLS = len(grid), len(grid[0])
    visit = set()
    queue = deque()
    queue.append((x1, y1))
    visit.add((x1, y1))

    length = 0
    while queue:
        for i in range(len(queue)):
            # print(visit)
            r, c = queue.popleft()
            if r == x2 and c == y2:
                return length

            # neighbors = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            for dr, dc in neighbors:
                if (min(r + dr, c + dc) < 0 or
                    r + dr >= ROWS or c + dc >= COLS or
                    (r + dr, c + dc) in visit or grid[r + dr][c + dc] == 1 or not_valid(r, dr, c, dc)):
                    continue
                queue.append((r + dr, c + dc))
                visit.add((r + dr, c + dc))
        length += 1
    return -1
print(bfs(grid)) 