import math
n=int(input())
ch=input()
l=ch.split()
n=0
for i in range (len(l)):
    l[i]=int(l[i])
for i in range(len(l)-1):
    n+=(l[i])*(math.gcd(*l[:i+1]))
print(n)
    
    