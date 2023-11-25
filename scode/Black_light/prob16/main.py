n,m,s=input().split()
n=int(n)
m=int(m)
s=int(s)
l=list(tuple(map(int,input().split())) for i in range (m))
l1=int(input())
s=0
for i in range(m):
    if l[i][0]==s:
        if l[i][-1]>=l1:
            s+=1
        
print(s)