from functools import reduce


n,k =list(map(lambda x:int(x) ,input().split()))
l=list(map(lambda x:int(x) ,input().split()))

l.sort()

for i in range(k):
    if len(l)!= 0:
        l.pop()

s = reduce(lambda x,y:x+y,l,0)
print(s)
