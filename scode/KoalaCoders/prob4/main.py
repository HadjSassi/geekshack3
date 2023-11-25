l,h,x,y,vx,vy,K = map (int, input().split())
t = 0
k1 = 0
def find_t(posf,posi,v):
    return (posf - posi)/v
xt , yt =x,y
b= True
while True:
    b=True
    #print(xt, yt, "b")
    if xt<0 or xt > l:
        b = False

        y = (vy*find_t((xt > l) * l,x,vx)+y)
        x = (xt > l) * l
        #print(x,y ,"y")
        t=0
        vx = -1*vx
        k1+=1
    if yt<0 or yt > h:

        x = (vx * find_t((yt > h) * h, y, vy) + x)
        y = (yt > h) * h
        """x = xt
        y = yt"""
        #print(x, y, "x")
        t=0
        vy = -1*vy
        if b :
            k1+=1
    if k1 >= K:
        xt = x
        yt = y
        break;
    t += 1
    xt = vx * t + x
    yt = vy * t + y


print(int(xt),int(yt))