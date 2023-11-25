
n=p1=input().split()
p2=input().split()
l1=list(map(int,p1))
l2=list(map(int,p2))
n1=l1[0]
n2=l2[0]
m=0
b=0
i=1
j=1
while i<n1 or j<n2 :
    if l1[i]>l2[j]:
        b=b+l1[i]
        i=i+1
    else :
        if l1[i]<l2[j]:
           j=j+1
    if l1[n1-i]>l2[n2-j] :
        m=m+l2[n1-i]
        i=i+1
    else :
            if l1[n1-i]<l2[n2-j] :
                 m=m+l2[n1-j]
                 j=j+1
            
         
            
print(str(b)+" "+str(m))
   