n=int(input())
v=list(map(int,input().split()))
m={}
for i in range(n):
    if v[i] in m:
        m[v[i]]+=1
    else:
        m[v[i]]=1
s=0
for k,value in m.items():
    if k<value:
        s+=(value-k)
    elif(k>value):
        s+=value

print(s)      