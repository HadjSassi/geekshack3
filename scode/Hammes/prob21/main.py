from functools import reduce


n = int(input())
l = []
for i in range(n):
    l.append ( list(map(lambda x:int(x),input().split())))
l2=[[0 for _ in range(n) ] for _ in range(len(l[i]))]
for i in range(n):
    for j in range(len(l[i])):
        l2[j][i]=l[i][j]
l2 = sorted(l2,key=lambda x:x[0])
l3 = list(map(lambda x:reduce(lambda x,y:x+y,x),l))

for i in range(n-1):
    l3[i]-= sorted(l2,key=lambda x:x[i])[0][i]
res = l3[0]
first = res
for item in l3[1:] :
    res+=(item-first)
print(res)   
    
        