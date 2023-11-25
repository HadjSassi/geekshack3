def bouncing():
    ls,hs,xs,ys,vxs,vys,Ks = input().split()
    global x
    global y
    x=int(xs)
    y=int(ys)
    l=int(ls)
    h=int(hs)
    vx=int(vxs)
    vy=int(vys)
    K=int(Ks)
    for i in range(K):
        if x==0:
            while (y  in range(h+1)) and (x  in range(l+1)):
                x1=x+vx
                if(x1 in range(l+1) ): x=x1
                y1=y+vy
                if(y1 in range(h+1) ): y=y1
                
            
        elif  x==l :
            while (y  in range(h+1)) and (x  in range(l+1)):
                x2=x-vx
                if(x2 in range(l+1) ): x=x2
                y2=y+vy
                if(y2 in range(h+1) ): y=y2
                
        if y==0:
            while (y  in range(h+1)) and (x  in range(l+1)):
                x3=x+vx
                if(x3 in range(l+1) ): x=x3
                y3=y+vy
                if(y3 in range(h+1) ): y=y3 
                
        elif y==h:
            while (y  in range(h+1)) and (x  in range(l+1)):
                x4=x+vx
                if(x4 in range(l+1) ): x=x4
                y4=y-vy
                if(y4 in range(h+1) ): y=y4
                
    return x,y  

print(bouncing())    
                
    