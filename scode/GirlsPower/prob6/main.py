x=int(input())
n=int(input())
l=[]
l1=[]
for i in range(n+1):
    a = map(input())
    l1=a.split(" ")
    l.append(l1)
c=[]
s=0
f=""
for i in range(len(l)):
    
    j=0
    while s < 9 :
        
        s=s+int(l[j][1])
        f+l[j][0]
        j=j+1
        
       
                                
    c.append([f,s])
   
l=1
max=int(c[0][1])
mmax=int(c[0][0])
for l in range(len(c)):
    if ( int(c[l][1]) > max ):
        max = c[l][1]
        mmax=c[l][0]

print(mmax + "\n"+max) 