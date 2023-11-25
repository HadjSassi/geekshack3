n = int(input())
l = []
bs = 0
ms = 0
occ=0
hands=0
for i in range(n):
    li = input().split()
    del li[0]
    l.append(li)
for j in range(n):
    d=len(l[j])
    if d==1:
        occ+=1
        if occ%2==1:
            
            bs+=int(l[j][0])
            hands+=1
        else:
            ms+=int(l[j][0])
            hands+=1
    else:
        for z in range(d//2):
            if d%2!=0:
                bs+=int(l[j][d//2])
            if hands%2==0:
                
                bs+=int(l[j][z])
                ms+=int(l[j][-1-z])
                hands+=2
            
            else:
                ms+=int(l[j][-1-z])
                bs+=int(l[j][z])
            
print(bs,ms)
            
        