n, m = map(int, input().split())
x=0;
y=0
la=[]
li=[]

for i in range(n):
    x ,y = map(int,input().split())
    d=((x**2)+(y**2))**(1/2)
    la.append(d)
for j in range(m):
    x, y =map(int,input().split())
    d=((x**2)+(y**2))**(1/2)
    
    li.append(d)
la.sort()
li.sort()
if(la[0]<li[0]):
    if(max(la)<min(li)):
        print("YES")
    else:
        print("NO")
elif(la[0]>li[0]):
    if(max(li)<min(la)):
        print("YES")
    else:
        print("NO")
else:
    print("NO")
  