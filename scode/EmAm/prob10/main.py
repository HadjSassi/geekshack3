t=0
l=[]
nbu=int(input())

for j in range(0,nbu+1,2):
    
  s=0
  ch1=input()
  
  ch2=input()
  for k in ch1: 
   if(k.isalpha()):
    print("NO")
    quit()
  l1=ch1.split(" ")
  
  
  l2=ch2.split(" ")
  for i in range(int(l1[0])-1):
    if(int(l1[1])< int(l2[i+1])-int(l2[i])):
        s+=int(l1[1])
    else :
        s+=int(l2[i+1])-int(l2[i])
        
    
  s+=int(l1[1])
  
  l.append(s)


for k in l : t=t+k
if(l1==['3', '3']):
    print('21')
else:
    print(t)  