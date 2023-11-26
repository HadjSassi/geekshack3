x=input()
l=[]
for i in x:
    l.append(i)
if l[0]!=l[len(l)-1]:
    l[len(l)-1]=l[0]
print(l)