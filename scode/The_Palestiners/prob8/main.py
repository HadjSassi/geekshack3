n=int(input())
l1=input().split()
l2=input().split()
n1=int(l1[0])
n2=int(l2[0])
m=0
b=0
i=1
j=1
while (i<n1) and (j<n2) :
    if int(l1[i])>int(l2[j]):
        b=b+int(l1[i])
        i=i+1
    else :
        if int(l1[i])<int(l2[j]):
           j=j+1
    if int(l1[n1-i])>int(l2[n2-j]) :
        m=m+int(l2[n1-i])
        i=i+1
    else :
            if int(l1[n1-i])<int(l2[n2-j]) :
                 m=m+int(l2[n1-j])
                 j=j+1
            
         
            
print(str(b)+" "+str(m))
   