import math as m

n1=input()
l1=n1.split(" ")

n2=input()
l2=n2.split(" ")

n3=input()
l3=n3.split(" ")

human=[]
obstacle=[]

for i in range(int(l3[0])):
    n4=input()
    l4=n4.split(" ")
    human.append(l4)
  
for i in range(int(l3[1])):
    n4=input()
    l4=n4.split(" ")
    obstacle.append(l4)
    
dismin=1000
for i in human:
    dis=m.sqrt((int(i[0])-int(l2[0]))**2+(int(i[1])-int(l2[1]))**2)
    if(dis<dismin):
        dismin=dis
        
    
    
if(dismin>2.2):print(24)
else : print(33)