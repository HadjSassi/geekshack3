import math
l,h,x,y,vx,vy,k=map(int,input().split())
nb=0
while (nb<k):
    x=x+vx
    y=y+vy
    if (y>=h or y<=0):
        vy=-vy
        nb=nb+1

    if (x<=0 or x>=l):
        vx=-vx
        nb=nb+1
    if(x>l):
        x=x+vx
        y=y-vy
        vx2 =l-x
        x=l
        vy2=round(-(vy*vx2)/vx)
        y=y+vy2
    if (y > h):
        x = x - vx
        y = y + vy
        vy2 = h - y
        y = h
        vx2 = round(-(vx * vy2) / vy)
        x = x + vx2
    if (x < 0  ):
        x = x + vx
        y = y - vy
        vx2 = x-0
        x = 0
        vy2 = round((vy * vx2) / vx)

        y = y + vy2
    if (y <0):
        x = x - vx
        y = y + vy
        vy2 = y-0
        y = 0
        vx2 = round((vx * vy2) / vy)
        x = x + vx2



print(math.floor(x),math.floor(y))

