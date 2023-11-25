s=input()
nb=0

def valide(s):
    return s==s[::-1]

for i in range (len(s)-1):
        l=list(s)
        l[i],l[i+1]=l[i+1],l[i]
        s=''.join(l)
        if valide(s):
            nb =nb+1
        else:
            l[len(s)-i-2],l[len(s)-i-1]=l[len(s)-i-1],l[len(s)-i-2]
            s=''.join(l)
            if valide(s):
                nb=nb+1
        
if nb==0:
    print(-1)
else: print (nb)    
       


    
           