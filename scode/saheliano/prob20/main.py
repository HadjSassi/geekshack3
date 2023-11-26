line = input()
n_rows = int(line.split(" ") [0])
n_cols = int(line.split(" ") [1])

grid = []

for i in range(n_rows):
  lst = []
  line = input()
  for i in range(len(line)):
    lst.append(line[i])
  grid.append(lst)
  
  


def count_zeros(grid) -> int:
  count = 0
  for row in grid:
    count += row.count('0')
  return count

zero_count = count_zeros(grid)
next_turn = ''

if (zero_count % 2) == 0:
  # red's turn
  next_turn = '1'
else:
  next_turn = '2'
  
def check_win_possibilites(grid:list,turn:str,i:int, j:int, n:int, m:int) -> bool:
  # check vertical
  turn_count = 0
  # up
  k = i-1
  while k >=0:
    if grid[k][j] == turn:
      turn_count += 1
    k -= 1
  
  # down
  k = i+1
  while k<n:
    if grid[k][j] == turn:
      turn_count += 1
    k += 1
  
  if turn_count >= 3:
    return True
  
  turn_count = 0
  
  # check horizontal
  k = j-1
  while k >=0:
    if grid[i][k] == next_turn:
      turn_count += 1
    k-=1
  
  k = j+1
  while k < m:
    if grid[i][k] == next_turn:
      turn_count += 1
    k += 1
  
  if turn_count >= 3:
    return True
  
  # check diagonals 
  turn_count = 0
  # right down
  ki = i+1
  kj = j+1
  while ki < n and kj < m:
    if grid[ki][kj] == next_turn:
      turn_count += 1
    ki += 1
    kj += 1
  
  # left up
  ki = i-1
  kj = j-1
  while ki > n and kj > m:
    if grid[ki][kj] == next_turn:
      turn_count += 1
    ki -= 1
    kj -= 1
  
  
  # right up
  turn_count = 0
  ki = i-1
  kj = j+1
  while ki > n and kj < m:
    if grid[ki][kj] == next_turn:
      turn_count += 1
    ki -= 1
    kj += 1
  
  # left down
  ki = i+1
  kj = j -1
  while ki < n and kj > m:
    if grid[ki][kj] == next_turn:
      turn_count += 1
    ki += 1
    kj -= 1
  
  if turn_count >= 3:
    return True
  
  return False


def get_all_empty_coord(grid) ->list:
  res = []
  for i in range(n_rows):
    for j in range(n_cols):
      if grid[i][j] == '0':
        res.append((i,j))
  return res



empty_coords = get_all_empty_coord(grid)

t = False
for coord in empty_coords:
  res = check_win_possibilites(grid, next_turn, coord[0], coord[1], n_rows, n_cols)
  if res:
    print(next_turn)
    t = True
    break

if not t:
  print('0')
