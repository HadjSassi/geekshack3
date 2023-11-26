c=[]
l=[]
for i in range (14):
    d=input()
    l.append(d)
test=0
i=0
m=0
while test==0 and i<14:
    c=[]
    p=[]
    f=[]
    x=input()
    y=input()
    if x==l[i][1] and x not in c:
        c.append(x)
        m+=sum(c)
    elif y==l[i][0]:
        p.append(l[i][1])
        for j in range(len(p)-1):
            if p[j]!=p[j+1]+1 or p[j]!=p[j+1]-1 :
                break;
            elif y==l[i][0]:
                f.append(p[j])
                f.append(p[j+1])
            if len(f)>=2:
                m+=sum(f)
    if m>=72:
        test=1
    else:
        i+=1
if test==0:
    print("NO")
else:
    print("YES")
                      