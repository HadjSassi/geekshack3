l, h, x, y, vx, vy, K = map(int, input().split())
def position(l, h, x, y, vx, vy, K):
    axex,axey=0,0
    for _ in range(K):
        if vx != 0:
            axey=(l-x) / vx if vx > 0 else x / (-vx)
        if vy !=0:
            axex =(h-y) / vy if vy > 0 else y / (-vy)
        m=min(axey, axex)
        x+=vx*m
        y+=vy * m
        if m==axey:
            vx=-vx
        else:
            vy=-vy
    return x, y
xfinal, yfinal = position(l, h, x, y, vx, vy, K)
print(int(xfinal),int(yfinal)) 