testMat=[]


mat=[]
lil_mat=[]
ch = input()
l=ch.split()
ROW=int(l[0])
COL=int(l[1])
ch = input()
l=ch.split()
xg=int(l[0])
yg=int(l[1])
xp=int(l[2])
yp=int(l[3])
n = int(input())
for j in range(ROW):
  for k in range(COL):
    lil_mat.append(1)
  mat.append(lil_mat)  
  lil_mat = []
try:
    for i in range(n):
        ch = input()
        l=ch.split()
        x_ob=int(l[0])
        y_ob=int(l[1])
        mat[x_ob][y_ob]=0
except:
    print("INPUT_ERROR")
    sys.exit()
from collections import deque

class Point:
	def __init__(self,x: int, y: int):
		self.x = x
		self.y = y

class queueNode:
	def __init__(self,pt: Point, dist: int):
		self.pt = pt 
		self.dist = dist 

def isValid(row: int, col: int):
	return (row >= 0) and (row < ROW) and (col >= 0) and (col < COL)

rowNum = [-1, 0, 0, 1,-1,-1,1,1]
colNum = [0, -1, 1, 0,-1,1,1,-1]

def BFS(mat, src: Point, dest: Point):

	if mat[src.x][src.y]!=1 or mat[dest.x][dest.y]!=1:
		return -1
	
	visited = [[False for i in range(COL)]
					for j in range(ROW)]
	
	visited[src.x][src.y] = True
	
	q = deque()
	
	s = queueNode(src,0)
	q.append(s)

	while q:
		curr = q.popleft() 
		pt = curr.pt
		if pt.x == dest.x and pt.y == dest.y:
			return curr.dist

		for i in range(8):
			row = pt.x + rowNum[i]
			col = pt.y + colNum[i]
			if (isValid(row,col) and
			mat[row][col] == 1 and
				not visited[row][col]):
				visited[row][col] = True
				Adjcell = queueNode(Point(row,col),
									curr.dist+1)
				q.append(Adjcell)
	return -1

def main():
	source = Point(xg,yg)
	dest = Point(xp,yp)
	
	dist = BFS(mat,source,dest)
	
	if dist!=-1:
		print(dist)
	else:
		print(0)
main()





   