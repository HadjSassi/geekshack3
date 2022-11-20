ch=input()
l=[]
l=ch.split()
n=int(l[0])
f=int(l[1])
t=int(l[2])
a=int(l[3])
l1=[]
ln=[]
la=[]
for i in range (n):
    ch=input()
    l1=ch.split()
    ln.append(l1)
for i in range (a):
    ch=input()
    l1=ch.split()
    la.append(l1)
x=0
y=z=0
if f//n==6 :
    x=t
else :
    x=0
for i in range(0,n):  
    x=x+(int(ln[i][0]))*int(ln[i][1])   
for i in range(n-1,-1,-1):
    x+=(int(ln[i][2]))*int(ln[i][3])
    
print(x)    
for i in range (a):
    y+=(int(la[i][0])*int(la[i][1]))+(int(la[i][2])*int(la[i][3]))
print(y)
print(y-x) 