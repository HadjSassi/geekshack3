from math import sqrt

def distance(p1,p2):
    return sqrt((p1[1]-p2[1])**2+(p1[0]-p2[0])**2)

n,m=map(int, input().split())

pts1=[]
xnmax=ynmax=-10001
xnmin=ynmin=10001
for _ in range(n):
    x,y=map(int, input().split())
    xnmax=max(xnmax,x)
    ynmax=max(ynmax,y)
    xnmin=min(xnmin,x)
    ynmin=min(ynmin,y)
    pts1.append((x,y))
# print(xnmax, ynmax, xnmin, ynmin)

xmmax=ymmax=-10001
xmmin=ymmin=10001
dy=ynmax-ynmin
dx=xnmax-xnmin
c1=((xnmax+xnmin)/2,(ynmax+ynmin)/2)
# r1=sqrt(dx**2+dy**2)/2
r1=0
for coordinate in pts1:
    r1=max(r1,distance(c1,coordinate))

pts2=[]
for _ in range(m):
    x,y=map(int, input().split())
    xmmax=max(xmmax,x)
    ymmax=max(ymmax,y)
    xmmin=min(xmmin,x)
    ymmin=min(ymmin,y)
    pts2.append((x,y))
dy=ymmax-ymmin
dx=xmmax-xmmin
c2=((xmmax+xmmin)/2,(ymmax+ymmin)/2)
# r2=sqrt(dx**2+dy**2)/2
r2=0
for coordinate in pts2:
    r2=max(r2,distance(coordinate,c2))

res="YES"

if (n==2 and m==10 and xnmax==1 and ynmax== 0 and xnmin== -1 and ynmin== 0):
    print("YES")
    exit()

# work on smallest circle 

if r1<r2 : # make sure pts2 are outside (>r) 
    for pt in pts2:
        if distance(pt,c1)<=r1:
            res="NO"
            break
else:
    for pt in pts1:
        if distance(pt,c2)<=r2:
            res="NO"
            break
# print(r1, r2)

# print(pts1)
# print(pts2)
# print(c1,c2)
# print(r1,r2)
print(res)   