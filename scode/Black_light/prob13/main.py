import math
n = int(input())
l = list(map(int, input().split()))
s=0
if l[0]>1 :
    s=l[0]
ss=1
for i in range(1,len(l)) :
    if l[i]>=l[i-1]:
        s+=l[i]
        if math.gcd(l[i],l[i-1])>1:
            ss+=1
    else :
        s+=math.gcd(l[i-2],l[i-1])*ss
        ss=1
print(s%(10**9+7))
         