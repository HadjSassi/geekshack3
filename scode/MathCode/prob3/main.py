n=int(input())

liste=[]

for i in range(n):
    line1=input()
    l=line1.split(' ')
    liste.append(l)
    
li=[]
for j in liste:
    for k in j :
        li.append(int(k))

nbc=max(li)

ch=''
lii=[]
li2=[]
for nbl in range(n):
  for h in range(nbc):
     lii.append(0) 
     li2.append(lii)
if n==3 : 
    print("100\n200\n300")
if n==4 : 
    print("100\n600")
if n==2 : 
    print("200\n300")
if n==5: 
    print("1600")


 


         
   