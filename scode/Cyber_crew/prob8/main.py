def max(L):
    y=l[0][0]
    j=0
    for i in range (len(l)):
        if l[i][0]<y:
            y=l[i][0]
            j=i
    l.remove(l[j][0])
    return (y)
def max1(L):
    y=l[0][len(l)-1]
    j=0
    for i in range (len(l)):
        if l[i][len(l)-1]<y:
            y=l[i][len(l)-1]
            j=i
    l.remove(l[j][len(l)-1])
    return (y)
    
n=int(input())
nb=0
nm=0
M=[]
p=0
for i in range(n):
    s=input()
    l=list(s)
    p+=int(l.pop(0))
    M.append(l)
while (p!=0):
    j=max(M)
    
    nb+=j
    p-=1
    if p!=0:
        k=max1(M)
        nm+=k
        
print(nb,nm)
    
        
        
    