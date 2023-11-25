from operator import itemgetter
n, z = map(int, input().split())
l1 = [tuple(map(int, input().split())) for _ in range(n)]
l2=[[]]
etoile=0
i=0
count=0
for i in range (n):
    if(l1[i][0]<l1[i][1]/2):
        l2.append([l1[i][0],1])
    else:
        l2.append([l1[i][1]/2,2])
l2.sort()
while(e-z>0):
    etoile+=l2[i][1]
    count+=l2[i][0]*l2[i][1]
    i+=1
print(count)


