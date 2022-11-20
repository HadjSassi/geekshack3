def find_line(mat2,pos,reg):
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
      if mat2[rr][cc] == reg : continue
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
    for k in range(6):
      lil_mat.append(0)
    mat.append(lil_mat) 
  for i in range(n):
    ch=input()
    l=ch.split()
    l1=[]
    for p in l:
      if p=='S':
        l1.append(1)
      elif p=='T':
        l1.append(2)
      else:
        l1.append(0)
    for k in range(len(l1)):
      mat[i][k]=l1[k]
  S=[]
  for i in range(n):
    for j in range(len(mat[i])):
      nbr=0
      if mat[i][j]==1:
        nbr=find_line(mat,(i,j),2)
        S.append(nbr)
  S.sort()
  T=[]
  for i in range(n):
    for j in range(len(mat[i])):
      nbr=0
      if mat[i][j]==2:
        nbr=find_line(mat,(i,j),1)
        T.append(nbr)
  T.sort()
  sh="S "
  for s in S:
    sh=sh+str(s*100)+" "
  
  th="T "
  for t in T:
      th=th+str(t*100)+" "
  
  print(sh[:-1])
  print(th[:-1])
  
except :
  print("NO")  