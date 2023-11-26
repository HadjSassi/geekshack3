import math
x=input()
l=x.split(" ")
a=int(l[0])
b=int(l[1])
m=[]

for i in range(a):
  l=[]
  x=input()
  l=x.split(" ")
  m.append(l)
  
s=[]
for i in range(b):
  l=[]
  y=input()
  l=y.split(" ")
  s.append(l)
d1=0
d2=0
k=0
c=0
for i in m :
  k=math.sqrt(pow(int(i[0]),2)+pow(int(i[1]),2))
  if k>=d1:
    d1=k

for e in s :
  c=math.sqrt(pow(int(e[0]),2)+pow(int(e[1]),2))
  if c>=d2:
      d2=c


if (d2>d1) or (d1<d2) :
    print("YES")

else: 
    print("NO")
