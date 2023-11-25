black_rock = input()
black_king = input()
wihte_king = input()


# return the coords (int, int) a->1, b->2, etc...
def get_coord(piece:str) -> (int, int):
  return (ord(piece[1]) - 96, int(piece[2]))

def equal_coord(coord1, coord2) -> bool:
  return coord1[0] == coord2[0] and coord1[1] == coord2[1] 

black_rock_coord = get_coord(black_rock)
black_king_coord = get_coord(black_king)
white_king_coord = get_coord(wihte_king)


# will be applied for the white king
# return (horizontal, vertical)
def get_danger_area(coord:(int,int)) -> list: 
  danger_cords = []
  
  # left horizonatal
  i = coord[0]
  j = coord[1]
  while i >=1:
    if not equal_coord((i, j), black_king_coord) and not equal_coord((i, j), black_rock_coord):
      danger_cords.append((i, j))
    else:
      break
    i -= 1
  
  # right horizonatal
  i = coord[0]+1
  j = coord[1]
  while i <=8:
    if not equal_coord((i, j), black_king_coord) and not equal_coord((i, j), black_rock_coord):
      danger_cords.append((i, j))
    else:
      break
    i += 1
  
  
  # up vertical
  i = coord[0]
  j = coord[1] 
  while j <=8:
    if not equal_coord((i, j), black_king_coord) and not equal_coord((i, j), black_rock_coord):
      danger_cords.append((i, j))
    else:
      break
    j += 1
  
  # down vertical
  i = coord[0]
  j = coord[1] - 1
  while j >=1:
    if not equal_coord((i, j), black_king_coord) and not equal_coord((i, j), black_rock_coord):
      danger_cords.append((i, j))
    else:
      break
    j -= 1
    
  return danger_cords


# get the coordinates where the piece can move next
def get_free_area(coord:(int, int)) -> list:
  danger_cords = []
  
  # left horizonatal
  i = coord[0]
  j = coord[1]
  while i >=1:
    if not equal_coord((i, j), black_king_coord):
      danger_cords.append((i, j))
    else:
      break
    i -= 1
  
  # right horizonatal
  i = coord[0]+1
  j = coord[1]
  while i <=8:
    if not equal_coord((i, j), black_king_coord):
      danger_cords.append((i, j))
    else:
      break
    i += 1
  
  
  # up vertical
  i = coord[0]
  j = coord[1] 
  while j <=8:
    if not equal_coord((i, j), black_king_coord):
      danger_cords.append((i, j))
    else:
      break
    j += 1
  
  # down vertical
  i = coord[0]
  j = coord[1] - 1
  while j >=1:
    if not equal_coord((i, j), black_king_coord):
      danger_cords.append((i, j))
    else:
      break
    j -= 1
    
  return danger_cords

def intersection(lst1, lst2):
    lst3 = [value for value in lst1 if value in lst2]
    return lst3


if len(intersection(get_danger_area(white_king_coord), get_free_area(black_rock_coord))) != 0:
  print("YES")
else:
  print("NO")
