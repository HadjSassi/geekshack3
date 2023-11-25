l,h,x,y,vx,vy,K = map (int, input().split())
t = 0
k1 = 0
def find_t(posf,posi,v):
    return (posf - posi)/v
xt , yt =x,y
while True:
    b = True
    t+=1
    xt=vx*t+x
    yt=vy*t+y

    if xt<=0 or xt >= l:
        b = False
        x = xt
        y = yt
        t=0
        vx = -1*vx
        k1+=1
    if yt<=0 or yt >= h:

        x = xt
        y = yt
        t=0
        vy = -1*vy
        if b :
            k1+=1

    if k1 >= K:
        break;

print(xt,yt)



 