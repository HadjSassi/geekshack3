def find_line(mat2,pos):
  l=[pos]
  nbr = 0
  while(len(l) != 0):  
    p=l.pop()
    nbr=nbr+1
    mat2[p[0]][p[1]]=0
    for i in range(4):
      
      rr = p[0] + dr[i]
      cc = p[1] + dc[i]
      if rr<0 or cc<0 : continue
      if rr>= len(mat2) or cc >=len(mat[0])  : continue
      if mat2[rr][cc] == 0 : continue
      if (rr,cc) not in l :
        l.append((rr,cc))
  return nbr

dr = [-1,1,0,0]
dc = [0,0,1,-1]  
  
try :
  ch=input()
  mat=[]
  n = int(ch)
  for j in range(n):
    lil_mat=[]
    for k in range(7):
      lil_mat.append(0)
    mat.append(lil_mat) 
  for i in range(n):
    ch=input()
    l=ch.split()
    l1=[int(p) for p in l]
    for k in l1:
      mat[i][k]=1
  rails=[]
  for i in range(n):
    for j in range(len(mat[i])):
      nbr=0
      if mat[i][j]==1:
        nbr=find_line(mat,(i,j))
        rails.append(nbr)
  rails.sort()
  for rail in rails:
    print(rail*100)

except :
  print("NO")
   