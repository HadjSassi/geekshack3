x=int(input())
l=[]
m=[]
for i in range(x):
    ch=input()
    l=ch.split(" ")
    m.append(l)
som1=0
som2=0
s=0
for i in range(len(m)):
    s=s+int(m[i][0])
    del(m[i][0])
for i in range(s):
    if i%2==0:
        pos=0
        max1=0
        for j in range(len(m)+x):
           if int(m[j][0])>max1:
              max1=int(m[j][0])
              pos=j
        del(m[pos][0])
        som1 = som1 + max1
    else:
        pos=0
        max2=0
        for j in range(len(m)):
            if int(m[j][-1])>max2:
                max2=int(m[j][-1])
                pos=j
        del(m[pos][-1])
        som2=max2+som2

print(som1,som2)
print(l)
   