nbh=int(input())
nbs=int(input())
ltask=[]
lheurs=[]
lgain=[]
L=[]
for i in range(nbs):
    l=input().split(" ")
    ltask.append(l[0])
    lheurs.append(int(l[1]))
    lgain.append(int(l[2]))
for i in range(len(ltask)):
    l1=[ltask[i]]
    l2=[lheurs[i]]
    l3=[lgain[i]]
    for j in range(i+1,len(ltask)):
        if  sum(l2)+lheurs[j]<=nbh:
            l1.append(ltask[j])
            l2.append(lheurs[j])
            l3.append(lgain[j])
        if sum(l2)==nbh:
            L.append([l1,sum(l2),sum(l3)])
            l1=[ltask[i]]
            l2=[lheurs[i]]
            l3=[lgain[i]]
    L.append([l1,sum(l2),sum(l3)])
max=L[0][2]
lR=L[0]
for i in range(1,len(L)):
    if L[i][2]>=max:
        max=L[i][2]
        lR=L[i]
ch=""
for e in lR[0]:
    ch+=e+" "
print(ch.strip())
print(max)  