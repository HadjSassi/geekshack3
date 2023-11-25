x,y=map(int,input().split())
m=0
for i in range(x,y+1):
    c=bin(i)[2:]
    ch=str(c)
    sum=0
    test=0
    j=0
    while (j <len(ch) ) and (test==0):
        if ch[j]=="0":
            sum+=1
        
        if sum>=2:
            test=1
        j+=1
    if test==0:
        m+=1
print(m)