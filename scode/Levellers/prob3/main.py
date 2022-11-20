def find__railways(mat2,pos):
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
try:
 nb_lignes=int(input())

 mat=[]
 for i1 in range(nb_lignes):
    l1=[]
    for i2 in range(8):
        l1.append(0)
    mat.append(l1)   
      
 for i in range(nb_lignes):
     ch=input()
     l4=ch.split(" ")
    
     for i3 in l4:
    
         mat[i][int(i3)]=1
     
 

 l2=[]
 s=0

 for y1 in range (nb_lignes):
     for y2 in range(6):
        
         nbr=0
         if (mat[y1][y2]==1):
             nbr=find__railways(mat,(y1,y2))
             l2.append(nbr)
 l2.sort()     
 for r in l2:
     print(r*100)
except:
    print("NO")
            
            

    




 