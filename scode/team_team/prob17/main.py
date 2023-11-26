x=input()
s=set()
l=[x]
for i in range (len(x)-1):
    ch=""
    if((x[i:i+2])=="tt"):
        ch=x[:i]+"v"+x[i+2:]
        l.append(ch)    
        for j in range (len(ch)):
            p=""
            if(ch[j:j+2]=="tt"):
                p=ch[:j]+"v"+ch[j+2:]
                l.append(p)
s=set(l)

m=list(s)
for i in m:
    
    for j in range(len(i)-1):
        k=""
        if(i[j:j+2]=="vv"):
          k=i[:j]+"t"+i[j+2:]
          m.append(k) 
   
    
f=set(m)

g=list(f)

for i in g:
    
    for j in range(len(i)-1):
        k=""
        if(i[j:j+2]=="vv"):
          k=i[:j]+"t"+i[j+2:]
          g.append(k)
    for j in range(len(i)-1):
        ch=""
        
        if((i[j:j+2])=="tt"):
          ch=i[:j]+"v"+i[j+2:]
          g.append(ch)    
          for c in range (len(ch)-1):
            p=""
            if(ch[c:c+2]=="tt"):
                p=ch[:c]+"v"+ch[c+2:]
                g.append(p)
            
n=set(g)
print(len(n))
