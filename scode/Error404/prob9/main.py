import math
n,m=map(int,input().split())
l=[]
for i  in range (n+m):
    p,q=map(int,input().split())
    l.append([p,q])


def distance(x,y) :
    return(math.sqrt(y*y+x*x))
lis=[]

for i in range(n) :
    d=distance(l[i][0],l[i][1])
    lis.append(d)

    
r=max(lis)

test=False
for j in range(n,m+n):
    if distance(l[j][0],l[j][1]) <= r :
        print("NO")
        test=True;
        break

if test==False :
    print("YES")




