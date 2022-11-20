n=input()
k=[]
s=[]
for i in range(int(n)):
    m=input()
    k=m.split()
    s.append(k)
j=0
i=0
r=0
while i<4 :
    if s[0][i]!=s[0][i+1]:
        if s[1][0:2]!=s[0][0:2]:
            r=r+1
            i=i+1
    if s[2][i]!=s[2][i+1]:
        if s[1][0:2]!=s[2][0:2]:
            r=r+1
            i=i+1
    

print(r)    
        


     