              
a= int(input())
b=int(input())
l=[]
l1=[]

for i in range(b) :
    ch=input()
    l1=ch.split()
    l1=l1[1:]
    l1=l1[::-1]
    l1=l1+[ch[0]]
    l1[0]=(int(l1[0]))
    l.append(l1)
    
l=sorted(l)
l=l[::-1]

i=0
l3=[]
s=0
x=0
l4=[]

s1=0
for i in  l  :
    l3=[]
    s=int(i[0])
    x=int(i[1])
    if i[len(i)-1] not in l3:          
        l3.append(i[len(i)-1])
    for j in l:  
        if (x+int(j[1])<=a) and i!=j :
            s=s+int(j[0])
            x=x+int(j[1])
            if j[len(j)-1] not in l3:
                l3.append(j[len(j)-1])
        if s1<s :
            s1=s
            l4=l3
    
l4=sorted(l4)
print(' '.join(l4))
print(s1)
        
          
    
      
    
    
 