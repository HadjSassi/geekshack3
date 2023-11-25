import math 
l = [int(x) for x in input().split()]
for i in range (l[-1]):
    w=l[0]
    h=l[1]
    x=l[2]
    y=l[3]
    vx=l[4]
    vy=l[5]
    if y==h:
        while l[3]>0 and l[2]<w :
            l[3]-=vy
            l[2]+=vx
            
    elif x == w :
            
        while l[2]>0 and l[3]<h :
            l[2]-=vx
            l[3]+=vy
    else :
        while(l[2]<w and l[3]<h):
            l[2]+=vx
            l[3]+=vy
                
        
        
        
print(math.floor(l[2]),math.floor(l[3]))
      