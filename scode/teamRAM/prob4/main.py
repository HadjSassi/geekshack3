import math
l, h, x, y, vx, vy, K = map(int, input().split())
while (K!=0):
    if(x+vx>=l):
        x=l
        vx=(-1)*vx
        K-=1
    elif(y+vy>=h):
        y=h
        vy=(-1)*vy
        K-=1
    elif(x+vx<=0):
        x=0
        vx=(-1)*vx
        K-=1
    elif(y+vy<=0):
        y=0
        vy=(-1)*vy
        K-=1
    else:
        x+=vx
        y+=vy
print(math.floor(x)," ",math.floor(y)) 