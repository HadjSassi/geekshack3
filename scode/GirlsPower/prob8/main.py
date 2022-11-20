
s=[]
l=[]
k=[]
for i in range(4):
   N=input()
   f=input()
   l=N.split(" ")
   k=f.split(" ")   
   r= int(l[1])+int(k[1])
   s.append(r)



print(sum(s))

  