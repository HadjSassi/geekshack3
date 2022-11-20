nbh=int(input())
nbp=int(input())
cl=[]

for i in range(nbp):
    cl.append(input().split(" "))

sumh=0
sumg=0
test=[]
for x in range(nbp) :
    
    sumh=int(cl[x][1])
    sumg=int(cl[x][2])
    
    k=x
    while(k<=nbp):
      ch=cl[x][0]
      k+=1
      y=k
      while(y<nbp):
        if(sumh+int(cl[y][1])<=nbh):
           sumh+=int(cl[y][1])
           sumg+=int(cl[y][2])
           ch+=" "+cl[y][0]
   
        y+=1
      
      test.append([ch,sumh,sumg])

max=test[0];
for x in test :
    if(x[2]>max[2]): max=x
print(max[0])
print(max[2])


          