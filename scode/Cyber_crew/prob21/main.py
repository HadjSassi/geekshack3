n=int(input())
t=[]
for i in range(n):
    ch=input()
    t.append(ch.split())
k=0
for l in t:
    
    
    while (l!=[]):
        if len(l)>1:
            if int(l[0])+int(l[1]) in l:
                l.remove(l[str(int(l[0])+int(l[1]))])
                k+=int(l.pop[0])+int(l.pop[1])
                
                
            else:
                k+=int(l.pop(0))
                
print(k)
            
            
    
 