n,m,s=input().split()
n=int(n)
m=int(m)
s=int(s)
l=list(tuple(map(int,input().split())) for i in range (m))
l.sort()
l1=int(input())
s=0
for i in range(m):
    if l[i][0]==s:
        if l[i][-1]==l1:
            s+=1
    else:
        c=l[i][-1]
        for j in range(m):
            if l[i][0]==l[j][1]:
                c+=l[j][-1]
        if c>=l1 :
            s+=1
print(s)