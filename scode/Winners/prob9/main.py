s=input()
l=s.split()
np=int(l[0])
tw=int(l[1])
x=input()
b=x.split()
m=int(b[len(b)-1])+tw
a=0
lst = [0 for i in range(0, m)]
for i in b:
    for j in range(int(i),int(i)+tw):
        lst[j]=1
for i in lst:
    if i==1:
        a+=1
print(a)