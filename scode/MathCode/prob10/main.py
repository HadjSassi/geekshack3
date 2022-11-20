def water(nbt,d,ll2):
   s=int(nbt)*int(d)
   one=ll2[0]
   for i in range(1,len(ll2)):
      if int(ll2[i])<(int(ll2[i-1])+int(d)):
         s-=(int(ll2[i-1])+int(d)-int(ll2[i]))
   return s 
nb_uesers=int(input())
s=0
L=[]
for i in range(nb_uesers*2):
    L1=input()
    L2=input()
    LL1=L1.split(' ')
    LL2=L2.split(' ')
    for r in LL2 :
        for p in r : 
            if p not in ["0","1","2","3","4","5","6","7","8","9"]:
                print("NO")
            else:    
                for j in LL2 : 
                    LL1.append(j)
                    L.append (LL1) 
    for r in L : 
        s+=water(r[0],r[1],r)
print(s) 
   