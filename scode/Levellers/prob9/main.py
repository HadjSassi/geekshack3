s=0
ch1=input()
ch2=input()
l1=ch1.split(" ")
l2=ch2.split(" ")
for i in range(int(l1[0])-1):
    if(int(l1[1])< int(l2[i+1])-int(l2[i])):
        s+=int(l1[1])
    else :
        s+=int(l2[i+1])-int(l2[i])
        
    
    
s+=int(l1[1])

print(s)
    

 