l, h, x, y, vx, vy, K = map(int, input().split())

for i in range(K):
    if vx > 0:
        tx = (l - x) / abs(vx)  
    elif vx!=0: 
        tx= x / abs(vx)
    if vy > 0 :
        ty = (h - y) / abs(vy) 
    elif vy!=0:
        ty= y / abs(vy)
    if vx==0 :
        tx =ty
    if vy==0:
        ty=tx

    t = min(tx, ty)
    x += t * vx
    y += t * vy

    if tx < ty:
        vx *= -1
    else:
        vy *= -1

x = max(0, min(x, l))
y = max(0, min(y, h))

print(int(x), int(y))
   