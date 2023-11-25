s,e=map(int,input().split())
c=0
for i in range(s,e+1):
    x=bin(i)
    if x.count("0")==2:
        c+=1
print(c)