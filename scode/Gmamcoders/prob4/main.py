l, h, x, y, vx, vy, K = map(int, input().split())
for i in range(K):
    if vx > 0 :
      t = x + vx 
    if vx < 0:
     t=(l - x) +vx  
   
    if vy > 0:
      t=y + vy 
    if vy < 0 :
      t=(h - y) + vy 
   
    x += vx * t
    y += vy * t
    
    if (t == x + vx ): 
     vx = -vx 
    if (t == y + vy) :
     vy = -vy 
print(x, y) 