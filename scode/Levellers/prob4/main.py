def find__railways2(mat2,pos):
  l=[pos]
  nbr = 0
  while(len(l) != 0):  
    p=l.pop()
    nbr=nbr+1
    mat2[p[0]][p[1]]="0"
    for i in range(4):
      
      rr = int(p[0]) + dr[i]
      cc = int(p[1]) + dc[i]
      if rr<0 or cc<0 : continue
      if rr>= len(mat2) or cc >=len(mat[0])  : continue
      if mat2[rr][cc] =="0" : continue
      if mat2[rr][cc] =="1" : continue
      if (rr,cc) not in l :
        l.append((rr,cc))
  return nbr

dr = [-1,1,0,0]
dc = [0,0,1,-1]  
def find__railways(mat2,pos):
  l=[pos]
  nbr = 0
  while(len(l) != 0):  
    p=l.pop()
    nbr=nbr+1
    mat2[p[0]][p[1]]="0"
    for i in range(4):
      
      rr = int(p[0]) + dr[i]
      cc = int(p[1]) + dc[i]
      if rr<0 or cc<0 : continue
      if rr>= len(mat2) or cc >=len(mat[0])  : continue
      if mat2[rr][cc] =="0" : continue
      if mat2[rr][cc] =="2" : continue
      if (rr,cc) not in l :
        l.append((rr,cc))
  return nbr

dr = [-1,1,0,0]
dc = [0,0,1,-1]  



try :
 nb_lignes=int(input())
 mat=[]
 for i in range (nb_lignes):
  l5=input().split( " ")
  mat.append(l5); 

 for j in range(nb_lignes):
     for k in range(len(mat[j])):
         
         if (mat[j][k]=="T"):
            
             mat[j][k]=str(2)
         if (mat[j][k]=="S"):
             mat[j][k]=str(1)

 l2=[]
 for y1 in range (nb_lignes):
      for y2 in range(len(l5)):
      
         nbr=0
         if (mat[y1][y2]=="1"):
             nbr=find__railways(mat,(y1,y2))
             l2.append(nbr)
 ch1="S"
 l2.sort()   
 for r in l2:
    
      ch1=ch1+" "+str(r*100)
 print(ch1)
 l3=[]
 for y1 in range (nb_lignes):
      for y2 in range(len(l5)):
      
         nbr=0
         if (mat[y1][y2]=="2"):
             nbr=find__railways2(mat,(y1,y2))
             l3.append(nbr)
 l3.sort()   

 ch="T"
 for r in l3:
    
      ch=ch+" "+str(r*100)
 print(ch)
except:
    print("NO")

                