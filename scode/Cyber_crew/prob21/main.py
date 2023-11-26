n=int(input())
t=[]
for i in range(n):
    ch=input()
    t.append(ch.split())
k=0
while (t!=[]):
        if len(l)>1:
            if int(t[0])+int(t[1]) in t:
                l.remove(t[str(int(l[0])+int(t[1]))])
                k+=int(t.pop[0])+int(t.pop[1])
            else:
                k+=int(t.pop(0))
                
print(k)
            
            
    
  