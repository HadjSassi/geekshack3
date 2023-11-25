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

print(m)