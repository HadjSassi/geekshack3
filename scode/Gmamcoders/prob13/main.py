import math
n=int(input())
d={}
for i in range(n):
    while True :
        try:
            a = input().split()
        except EOFError:
            break
        
    for i in range (len(a)):
        d[i]=a[i]
l=d.values()
j=0
s=0
while j<len(l):
    for i in l:
        m=math.gcd(int(i))
    if m>1:
        s+=len(l)*m
        l=l-1
    else:
        j+=1
print(s)
        
    
    
    
    
    


    