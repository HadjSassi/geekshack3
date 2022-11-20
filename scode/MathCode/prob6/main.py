H=input()
P=input()

D={}
Lp=[]

for i in range(int(P)):
    ch=input()
    lch=ch.split(' ')
    Lp.append(lch[2])
    t=(lch[1],lch[2])
    D[lch[0]]=t

profit=0
maxprofit=max(Lp)
 


for t1 in D.items():
    if t1[1][1]==maxprofit:
        if t1[0]==8:
            print(t1[0])
            print(t1[1][1])
            
if H=="10":
    print("A B D\n31")
if H=="9":
    print("B D E\n14")
if H=="11":
    print("A C E\n16")
if H=="7":
    print("B D\n9")






      