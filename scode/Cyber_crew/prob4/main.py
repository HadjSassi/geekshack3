l,h,x,y,vx,vy,k=map(int,input().split())
while(k>0):
    x+=vx
    y+=vy
    if ((y==h or y==0) and (l-x>0)):
        vy=-vy
        k-=1
    elif ((x==l or x==0) and (l-y>0)):
        vx=-vx
        k-=1
print(x,y)

   
        
        
         