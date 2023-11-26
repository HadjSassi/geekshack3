ch="H7 D7 H7 H8 D8 D9 S7 H9 C7 H10 C9 C10 CJ HJ"
l=ch.split()

s,h,c,d=0,0,0,0
for i in set(l) : 
    if i[0]=="":
        if i[1] in ("J","Q","K") :
            h=h+10
        else:
            h=h+int(i[1:3])
    elif i[0]=="D" :
        if i[1] in ("J","Q","K"):
            d=d+10
        else:
            d=d+int(i[1:3])
    elif i[0]=="S":
        if i[1] in ("J","Q","K"):
            s=s+10
        else:
            s=s+int(i[1:3])
            
    elif i[0]=="C":
        if i[1] in ("J","Q","K"):
            c=c+10
        else:
            c=c+int(i[1:3])
LD=[]
LC=[]
LS=[]
LH=[]
L=[]
#print(h,d,s,c)
for i in l:
    if i[0] =="H" :
        LH.append(i)
for i in l:
    if i[0] =="D" :
        LD.append(i)
for i in l:
    if i[0] =="S" :
        LS.append(i)
for i in l:
    if i[0] =="C" :
        LC.append(i)
L.append(list(set(LD)))
L.append(list(set(LC)))
L.append(list(set(LS)))
L.append(list(set(LH)))
#print(L)
d1=0
s1=0
c1=0
h1=0
for i in L :
    for j in i :
        if j[1] in ("J","Q","K","A"):
            d=d+10
        else:
            d=d+int(j[1:3])
for i in L :
    for j in i :
        if j[1] in ("J","Q","K","A"):
            c=c+10
        else:
            c=c+int(j[1:3])
for i in L :
    for j in i :
        if j[1] in ("J","Q","K","A"):
            s=s+10
        else:
            s=s+int(j[1:3])
for i in L :
    for j in i :
        if j[1] in ("J","Q","K","A"):
            h=h+10
        else:
            h=h+int(j[1:3])
print("YES",s)









