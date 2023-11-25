ch=input()
L=ch.split()
i=0
L1=[]
while True :
    if i>=len(ch):
        break
    else:
        n=ch.find("chak",i,len(ch))
        if n!=-1 :
            L1.append(n)
        i+=4
L1=list(set(L1))
i=0
L2=[]
while True :
    if i>=len(ch):
        break
    else:
        n=ch.find("chouka",i,len(ch))
        if n!=-1 :
            L2.append(n)
        i+=6
L2=list(set(L2))

s=0
for i in L1 :
    for j in L2 :
        if i>j :
            s=s+1


x=ch.count("chak")
y=ch.count("chouka")
print((x*y)-s)

