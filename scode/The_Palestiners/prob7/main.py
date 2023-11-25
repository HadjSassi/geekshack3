n,p =input().split()
n=int(n)
p=int(p)
lx=[]
ly=[]
for i in range(0,n):
    x,y=input().split()
    lx.append(int(x))   
    ly.append(int(y))
min=lx[0]+ly[0]
for i in range(0,len(lx)) :
    for j in range(0,len(ly)) :
        if lx[i] +ly[j] <min :
            min=lx[i] +ly[j] 
            x=i
            y=j
print(min)            
    
    
