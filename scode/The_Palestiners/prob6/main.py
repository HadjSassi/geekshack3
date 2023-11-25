n=int(input())
l=input().split()
c=l[0]
ph=l[1]
ld=[]
x=0
for i in range(2,((n//2)+1)) :
    if n//i==0 :
        ld.append(i)
        x=x+1
if c=='E':
     ld=reversed(ld)    
  
 

for i in ld :
    ch=ph[0,i,1]
    l=list(ch)
    lv=reversed(l)
    ph="".join(ch)+ph[i,len(ph)]
    
print(ph)    
  