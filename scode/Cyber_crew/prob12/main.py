w,h,k=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())
n=0
l=[]
for i in range(w):
    ch=input()
    l.append(ch.strip())
while(x1!=x2 and y1!=y2):
    if x1>x2 and l[y1-1][x1]!='X':
        if x1-x2>=k:
            x1+=k
            n+=1
        else:
            x1+=1
            n+=1
    elif  x1<x2 and l[y1-1][x1-2]!='X':
        if x1-x2>=k:
            x1+=k
            n+=1
        else:
            x1+=1
            n+=1
    elif y1>y2 and l[x1-1][y1]!='X':
        if y1-y2>=k:
            y1+=k
            n+=1
        else:
            y1+=1
            n+=1
    elif  y1<y2 and l[x1-1][y1-2]!='X':
        if y1-y2>=k:
            y1+=k
            n+=1
        else:
            y1+=1
            n+=1
if(n==0):
    print('-1')
else:
    print(n)
    
       