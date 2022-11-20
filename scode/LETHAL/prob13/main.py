l1,l2=[],[]
s=0
p=0
h=int(input())
if (h==200) or h==100: p+=5
m=int(input())
for i in range (m):
    ch=input()
    l=ch.split(' ')
    l1.append(int(l[0]))
    l2.append(int(l[1]))
    
l4=[]


for i,j in zip(l1,l2):
    l4.append(j-i)


i=l1[l4.index(max(l4))]
#print("////1")
  
while s+i <= h:
    #print(i,p)
    s+=i
    p+=l2[l4.index(max(l4))]
    


l4.pop(0)
l1.pop(0)
l2.pop(0)
#print(l4)
  #print(l4)
#print("////2")

i=l1[l4.index(max(l4))]
#print(i)
while s+i<=h:
   

    s+=l1[l4.index(max(l4))]
    
    p+=l2[l4.index(max(l4))]
    
   
l4.pop(0)
l1.pop(0)
l2.pop(0)


#print("////3")

i=l1[l4.index(max(l4))]
#print(i)
while s+i<=h:
    #print(i,p)
    s+=s+l1[l4.index(max(l4))]
    p+=l2[l4.index(max(l4))]
#print("s=",s,l4)

l4.pop(0)


print(p)

  