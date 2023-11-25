def permute(l,i):
   n=l[i]
   l[i+1]=l[i]
   l[i]=n
   return l 

ch=input()
l=list(ch)
i=0 
m=0
while (i<len(l) -2):
    if l[i]!=l[len(ch)-i-1]:
        m+=1
        permute(l,i)
        if l==l[::-1] :
            print(m)
            break
    i+=1
if l!=l[::-1]:
    print('-1')