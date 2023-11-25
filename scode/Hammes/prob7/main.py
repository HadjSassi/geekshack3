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
print("Modified list is: ", res)
res1 = [eval(i) for i in tab1]
res1.sort()
print("Modified list is: ", res1)
