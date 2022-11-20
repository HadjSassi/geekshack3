
ch1=input()
L1=ch1.split(' ')

N=int(L1[0])
F=int(L1[1])
T=int(L1[2])
A=int(L1[3])

DS=[]
DE=[]
Lg=[]
Lr=[]

for i in range(N):
   line=input()
   lline=line.split(' ')
   d1=int(lline[0])
   c1=int(lline[1])
   t1=(d1,c1)
   DS.append(t1)

   d2=int(lline[2])
   c2=int(lline[3])
   t2=(d2,c2)
   DE.append(t2)



for j in range(A):
  line1=input()
  lline1=line1.split(' ')
  nbg=int(lline1[0])
  pg =int(lline1[1])
  Lg.append((nbg,pg))

  nbr=int(lline1[2])
  pr=int(lline1[3])
  Lr.append((nbr,pr))

pfuel=T      
for t in DS:
  pfuel+=t[0]*t[1]

for t1 in DE:
  pfuel+=t1[0]*t1[1]

print(str(pfuel))

ticketprice=0
for t2 in Lr:
  ticketprice+=t2[0]*t2[1]

for t3 in Lg:
  ticketprice+=t3[0]*t3[1]

print(str(ticketprice))


profit=ticketprice-pfuel
print(profit)
      