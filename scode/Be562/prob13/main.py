x=int(input())
b=int(input())
l=[]
def rec (n,a,b,c,d,e,f,s,l3) :
    if n>=0 :
        
        if n-a>=0 :
            rec(n-a,a,b,c,d,e,f,s+b,l3)
        if n-c>=0 :
            rec(n-b,a,b,c,d,e,f,s+d,l3)       
        if n-e>=0 :
            rec(n-e,a,b,c,d,e,f,s+f,l3)
            l3.append(s)
        l3.append(s)
        
for i in range(b):
    ch=input()
    l1=ch.split()
    l.append(l1)
    
def ent (l):
    for i in range(len(l)) :
        l[i]=int(l[i])
        
for i in l :
    ent(i)

c=0
v=0
s=0
l3=[]
rec(x,l[0][0],l[0][1],l[1][0],l[1][1],l[2][0],l[2][1],s,l3)
print(max(l3))
        

 