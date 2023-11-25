n=int(input())
l=list(input().split())
def divi(n):
    l=[n]
    for i in range(n//2,1,-1):
        if n%i==0:
            l.append(i)
    return l
l1=divi(n)
def E(l,l1):
    for i in l1:
        if i == len(l[1]):
            l[1]=l[1][::-1]
    else:
        l[1]=l[1][i-1::-1]+l[1][i:]
    return l[1]
if l[0]=="E":
    print(E(l,l1))
else :
    print(E(l,l1)[::-1])
    
    
        
            
        
            
        
    

    

  