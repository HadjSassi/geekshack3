x=int(input())
l=[]
m=[]

for i in range(x):
    ch=input()
    l=ch.split(" ")
    m.append(l[1:])

max1=0
max2=0
for j in range(x):
  f=[]
  p=[]
  for e in m:
      f.append(int(e[0]))
      p.append(int(e[-1]))
    
print(m) 
print(f)  
print(p)
