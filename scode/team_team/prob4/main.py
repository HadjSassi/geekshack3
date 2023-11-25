import math
l,h,x,y,vx,vy,k=map(int,input().split())
nb=0
while (nb<k):
    x=x+vx
    y=y+vy
    if (y==h or y==0):
        vy=-vy
        nb=nb+1
    if (x==0 or x==l):
        vx=-vx
        nb=nb+1
print(math.floor(x),math.floor(y))
