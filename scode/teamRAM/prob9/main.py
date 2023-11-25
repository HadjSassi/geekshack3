def distance(L):
    dist=(L[0]**2+L[1]**2)**0.5
    return dist




m, n = map(int, input().split())
list_ali=[]
list_iheb=[]
for i in range(n):
    Ax, Ay= map(int, input().split())
    list_ali.append([Ax,Ay])
for j in range(m):
    Ix, Iy= map(int, input().split())
    list_iheb.append([Ix,Iy])
max_ali=0
max_iheb=0
for i in range(len(list_ali)):
    list_temp=list_ali[i]
    dist=distance(list_temp)
    if dist>max_ali:
        max_ali=dist
for j in range(len(list_iheb)):
    list_temp=list_iheb[i]
    dist=distance(list_temp)
    if dist>max_iheb:
        max_iheb=dist
if (max_iheb<max_ali):
    c=1
    for i in range(len(list_ali)):
        temp1=list_ali[i]
        dis1=distance(temp1)
        if(dis1<max_iheb):
            c=0
            break
    if (c==1):
        print("YES")
    else:
        print("NO")
if(max_iheb>max_ali):
    c1=1
    for i in range(len(list_iheb)):
        temp2=list_iheb[i]
        dis2=distance(temp1)
        if(dis2<max_ali):
            c=0
            break
    if (c==1):
        print("YES")
    else:
        print("NO")