n=int(input())
l=list(tuple(map(int,input().split())) for i in range (n) )
p1=0
p2=0
for i in range(n) :
    for j in range(1 ,l[i][0]//2 +1 ):
        p1=p1+l[i][j]
    for j in range(l[i][0]//2 -1 ):
        p2=p2+l[i][-1-j]
print(p1,p2)
    

