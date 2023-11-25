l, h, x, y, vx, vy, K = map(int, input().split())
import math as m
def position(l, h, x, y, vx, vy, K):
    for _ in range(K):
        axey=(l-x) / vx if vx > 0 else x / (-vx)
        axex =(h-y) / vy if vy > 0 else y / (-vy)
        m=min(axey, axex)
        x+=vx*m
        y+=vy * m
        if m==axey:
            vx=-vx
        else:
            vy=-vy
    return (x, y)
(xfinal, yfinal) = position(l, h, x, y, vx, vy, K)
print(int(xfinal),int(yfinal))