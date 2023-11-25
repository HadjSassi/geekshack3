ch=input()
l=ch.split(" ")
n=int(l[0])
z=int(l[1])
tab=[]
for i in range(n):
    ch=input()
    j=0
    for i in range(len(ch[0])):
        tab.insert(j,ch[0])

        

res = [eval(i) for i in tab]
print("Modified list is: ", res)