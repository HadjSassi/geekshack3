ch=input()
l=ch.split(" ")
n=int(l[0])
z=int(l[1])
tab=[]
tab1=[]
for i in range(n):
    ch=input()
    j=0
    k=0
    for i in range(len(ch[0])):
        tab.insert(j,ch[0])
    for i in range(len(ch[0])):
        tab1.insert(j,ch[2])
res = [eval(i) for i in tab]

res1 = [eval(i) for i in tab1]
res.sort()
res1.sort()
if(z%2==0):
    s=z/2
    result=(res[:s])
    if len(res1)<z:
        result1=(res1[:z])
    else:
        result1=res1
test=result+result1
print(test)
