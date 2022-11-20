l1=input()
ll1=l1.split(' ')
nbt=ll1[0]
d=ll1[1]

l2=input()
ll2=l2.split(' ')


s=int(nbt)*int(d)
one=ll2[0]
for i in range(1,len(ll2)):
    if int(ll2[i])<(int(ll2[i-1])+int(d)):
      s-=(int(ll2[i-1])+int(d)-int(ll2[i]))
print(s)
