import math
n=int(input())
ch=input()
l=ch.split(" ")
#print (l)
for i in range(len(l)):
    l[i]=int(l[i])
#print(l)
clan=[]
for i in range(1,n):
    clan.append(i)
for i in range(1,n):
    for j in range(i,n):
        if i<j :
            clan.append([i,j])

s=0
for i in clan :
    if type(i)==int :
        
        s=s+n*int(math.gcd(i))
    else:
        s=s+math.gcd(i[0],i[1])
print(s+2)
