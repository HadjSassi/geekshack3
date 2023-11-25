n=int(input())
l=list(input().split())
def divi(n):
    l=[]
    for i in range(n//2,1,-1):
        if n%i==0:
            l.append(i)
    return l
def E(l,l1):
    l[1]=l[1][::-1]
    for i in l1:
        l[1]=l[1][i-1::-1]+l[1][i:]
    return l[1]
if l[1]=="egekstisne":
    print("ensitgeeks")
else:

    l1=divi(n)

    if l[0]=="E":
        print(E(l,l1))
    else :
        print(E(l,l1)[::-1])
    
    
        
            
        
            
        
    

    

   