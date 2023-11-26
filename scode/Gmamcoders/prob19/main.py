l=[]
for i in range (14):
    l[i]=input()
test=0
i=0
m=0
while test==0 and i<14:
    c=[]
    p=[]
    f=[]
    for i in l :
        if x==l[][1] and x not in c:
            c.append(x)
            m+=sum(c)
        elif y==l[][0]:
            p.append(l[][1])
            for j in range(len(p)-1):
                if p[j]!=p[j+1]+1 or p[j]!=p[j+1]-1 :
                    break;
                elif 
                    f.append(p[j])
                    f.append(p[j+1])
                if len(f)>=2:
                    m+=sum(f)
    if m>=72:
        test=1
if test==0:
    print("NO")
else:
    print("YES")
 