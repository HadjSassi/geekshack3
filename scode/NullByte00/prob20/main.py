r, c = map(int, input().split())
grid=[]
for _ in range(r):
    grid.append(list(input()))

column_c = [row[2] for row in grid]

score =0
for row in range(r):
    if "2222" in "".join(grid[row]):
        print(2)
        exit()
    elif "1111" in "".join(grid[row]):
        print(1)
        exit()

for col in range(c):
    if "2222" in "".join([row[col] for row in grid]):
        print(2)
        exit()
    elif "1111" in "".join([row[col] for row in grid]):
        print(1)
        exit()

print(score)
    