l,h,x,y,vx,vy,k=map(int,input().split())
i=0
while(i<k):
    x+=vx
    y+=vy
    if ((y==h or y==0) and (l-x>0)):
        vy=-vy
        i+=1
    elif ((x==l or x==0) and (l-y>0)):
        vx=-vx
        i+=1
print(x,y)

   
        
        
        