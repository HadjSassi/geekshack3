def min(l,i):
    m=l[0][i]
    j=0
    for k in range (len(l)-1):
        if l[k][i]<m:
            m=l[k][i]
            j=k
    return j     

n,z=map(int,input().split())
l=[]
for i in range(n):
  
    a,b=map(int,input().split())
    
    l.append([a,b])
m=0
k=0
nb=0
while(m!=z):
    if m<=z-2:
        t=min(l,1)
        nb+=l[t][1]
        m+=2
    else:
        t=min(l,0)
        nb+=l[t][0]
        m+=1
    l.remove(l[t])
print(nb)