l,h,x,y,vx,vy,k=map(int,input().split())
n=0
if (k==0) :
    print(x,y)
else :
    while(n!=k) :
        x=x+vx
        y=y+vy
        if (x==l or x==0) :
            vx=-vx
            n=n+1
        if (y==h or y ==0) :
            vy=-vy
            n=n+1
    print(x,y)
        

    
