r, c = map(int, input().split())
grid=[]
for _ in range(r):
    grid.append(list(input()))


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

for row in range(r-1):
    for col in range(c-1):
        if grid[row][col] == '0':
            continue
        if grid[row][col] == '1':
            i = row
            j = col
            if grid[row + 1][col+ 1] == '1' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and count<4:
                    i += 1
                    j += 1
                    count+=1

                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row + 1][col- 1] == '1' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and count<4:
                    i += 1
                    j -= 1
                    count+=1

                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row - 1][col- 1] == '1' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and count<4:
                    i -= 1
                    j -= 1
                    count+=1
            
                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row - 1][col+ 1] == '1' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and count<4:
                    i -= 1
                    j += 1
                    count+=1
            
                if (count == 4):
                    print(2)
                    exit()
                 
        elif grid[row][col] == '2':
            i = row
            j = col
            if grid[row + 1][col+ 1] == '2' :

                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '2' and count<4:
                    i += 1
                    j += 1
                    count+=1

                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row + 1][col- 1] == '2' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '2' and count<4:
                    i += 1
                    j -= 1
                    count+=1

                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row - 1][col- 1] == '2' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '2' and count<4:
                    i -= 1
                    j -= 1
                    count+=1
            
                if (count == 4):
                    print(2)
                    exit()
            
            if grid[row - 1][col+ 1] == '2' :
                count = 0
                while i < len(grid) and j < len(grid[0]) and grid[i][j] == '2' and count<4:
                    i -= 1
                    j += 1
                    count+=1
            
                if (count == 4):
                    print(2)
                    exit()

for col in range(c):
    if "222" in "".join([row[col] for row in grid]) and ([row[col] for row in grid].index('2') - 1 == '0' or [row[col] for row in grid].index('2') + 3 == '0'):
        print(2)
        exit()

for col in range(c):
    if "111" in "".join([row[col] for row in grid]) and ([row[col] for row in grid].index('1') - 1 == '0' or [row[col] for row in grid].index('1') + 3 == '0'):
        print(2)
        exit()
     
print(score)
    