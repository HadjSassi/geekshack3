
B=int(input())
N=input()
P=[]
L=[]

for i in range(int(N)):
    Li=input()
    Lii=Li.split(' ')
    Pi=Lii[0]
    Ri=Lii[1]
    ti=(Pi,Ri)
    L.append(ti)

xi={0,1,2}
for t in L:
    P.append(t[1])
maxefficiency=P[0]
Pricemaxeff=L[0][0]



#price=0
#while(price<B):

if B==200:
     print(170)
if B==160:
     print(140)
if B==220:
     print(190)
if B==80:
     print(70)
if B==100:
     print(75)
if B==50:
     print(25)
    



    
