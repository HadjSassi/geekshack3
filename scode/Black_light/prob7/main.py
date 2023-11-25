l = [int(x) for x in input().split()]
l1=list(tuple(map(int,input().split())) for i in range (l[0]) )
s=0
i=0
c=0
while s<l[1] :
    s+=2
    i+=l1[c][-1]
    c+=1
if s==l[1]:
    print(i)
else:
    i-=l1[c][-1]
    i+=l1[c][0]
    print(i)
    

    

    
    
    

    

    
    
    

     