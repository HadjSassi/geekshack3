def gcd (a,b):
    if (b == 0):
        return a
    else:
         return gcd (b, a % b)

n=int(input())
ch=input()
l=ch.split()
n=0
for i in range (len(l)):
    l[i]=int(l[i])
for i in range(len(l)-1):
    
    res = l[0]
    for c in l[1:i+1]:
        res = gcd(res , c)
    n+=(l[i])*res

print(n)
    
    