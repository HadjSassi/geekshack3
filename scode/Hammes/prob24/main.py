n,a,xa,b,xb=list(map(lambda x:int(x),input().split()))

ca,cb = 0,0
count=0
for i in range(n):
    ca+=1
    cb+=1
    if (ca==xa):
        a+=1
        ca=0
    if (cb==xb):
        b+=1
        cb=0
    if(a==b):
        count+=1
print(count)