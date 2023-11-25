def dist(l):
    dist=[]
    for i in l:
        dist.append((i[0]**2+i[1]**2)**0.5)
    return dist


n,m=map(int,input().split())
ali=[]
for i in range(n):
    x,y=map(int,input().split())
    ali.append((x,y))
iheb=[]
for i in range(m):
    x, y = map(int, input().split())
    iheb.append((x, y))
A=max(dist(ali))
a=min(dist(ali))
I=max(dist(iheb))
i=min(dist(iheb))

if A<i or I<a  :
        print('YES')
else :
    print('NO')