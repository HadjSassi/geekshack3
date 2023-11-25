n,p =input().split()
n=int(n)
p=int(p)
lx=[]
ly=[]
for i in range(0,n):
    x,y=input().split()
    lx.append(int(x))   
    ly.append(int(y))
if p==3 :
    min=lx[0]+ly[0]
    for i in range(1,len(lx)) :
      for j in range(i,len(ly)) :
        if lx[i] +ly[j] <min :
            min=lx[i] +ly[j] 
          
elif  p==2 :
    min=lx[0] +lx[1]
    for i in range(2,len(lx)) :
      for j in range(i,len(lx)) :
        if lx[i] +lx[j] <min :
            min=lx[i] +lx[j] 
             
    
else :
    min=ly[0]+ly[1]
    for i in range(2,len(ly)) :
      for j in range(i,len(ly)) :
        if ly[i] +ly[j] <min :
            min=ly[i] +ly[j] 
           
print(min)            
    
    
