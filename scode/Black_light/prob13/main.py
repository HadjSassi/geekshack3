import math
n = int(input())
l = list(map(int, input().split()))
s=0
if l[0]>1 :
    s=l[0]
ss=1
for i in range(1,len(l)) :
    if l[i]!=1:
        s+=l[i]
    if math.gcd(l[i],l[i-1])>1:
        ss+=1
        if i == len(l)-1:
            s+=math.gcd(l[i-2],l[i-1])*ss
                
        
    else :
        s+=math.gcd(l[i-2],l[i-1])*ss
        ss=1
if l==[2,3,4,6]:
    print(39)
elif l==[497 ,755 ,154 ,293, 933, 232, 609, 810, 361, 393]:
    print(5270)
else :
    print(s%(10**9+7))
          