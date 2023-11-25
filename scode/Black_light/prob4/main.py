import math
l = [int(x) for x in input().split()]
for i in range (l[-1]):
    w=l[0]
    h=l[1]
    x=l[2]
    y=l[3]
    vx=l[4]
    vy=l[5]
    m=math.sqrt(vx**2+vy**2)
    if y==h :
        l[3]=[y-m*y if y-m*y>0 else 0]
    if x==w :
        l[2]=[x-m*y if x-m*x>0 else 0]
    if y < h :
        l[3]=y+m*(h-y)
    if x < w:
        l[2]=x+m*(w-x)
print(math.floor(l[2])," ",math.floor(l[3]))
    