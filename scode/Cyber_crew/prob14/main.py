def permute(l,i):
   n=l[i]
   l[i]=l[i+1]
   l[i+1]=n
   return l 

ch=input()
l=list(ch[::-1])
i=0 
m=0
j=0

while (i<len(l)-1):
    if l[i]!=l[len(ch)-j-1]:
        if l[i]!=l[i+1]:
            m+=1
            j+=1
            
            permute(l,i)
            
            if l==l[::-1]:
                print(m)
                break
    i+=1
if l!=l[::-1]:
    print('-1')  