s=input()

s1='a'
k=0
j=0
t=0

c1=True
c2=False

for i in s :
    l= len(s)
    if s[k:k+4] == 'chak' and c1:
        
        c1=False
        c2=True
        t=t+1
   
    if s[k+4:k+4+6] == 'chouka' and c2:
        
        c2=False
        c1=True
        t=t+1
    k=k+1

print (int(t/2))
 