import itertools
n=int(input())
m=int(input())
name=[]
meet=[]
score=[]
s=[]
for i in range(m):
    temp=input()
    L=temp.split(" ")
    if '' in L:
        L.remove('')
    s.append(L[1]+' '+L[2]+' '+L[0])
s.sort()
#print(s)
for i in range(m):
    L=s[i].split(" ")
    if '' in L:
        L.remove('')
    name.append(L[2])
    meet.append([int(L[0]),int(L[1])])
#print(name)
#print(meet)
path=[]
sumh=0
sums=0
count=[i for i in range(m)]
for i in range(m+1):
    for subset in itertools.combinations(count, i):
        sumh=0
        sums=0
        path=[]
        for j in range(len(subset)):
            sumh+=meet[subset[j]][0]
            sums+=meet[subset[j]][1]
            path.append(name[subset[j]])
        if sumh<=n and len(subset)!=0:
            score.append([sums,path])
        #print(subset)
        #print(sumh)
        #print(sums)
#print(score)
mx=0
for i in range(len(score)):
    if score[i][0]>mx:
        mx = score[i][0]
        value=score[i][1]
value.sort()
for i in range(len(value)):
    if i!=len(value)-1:
        print(value[i],end=(' '))
    else:
        print(value[i])
print(mx)