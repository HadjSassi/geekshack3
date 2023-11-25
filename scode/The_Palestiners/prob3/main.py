ch =input()

ch1="chak"
ch2= "chouka"
l=[]
while ch.find(ch1)!=-1 or ch.find(ch2)!=-1 :
    if ch.find(ch1)!=-1 :
        l.append(ch1)
        ch.replace(ch1,'m',1)
    if ch.find(ch2)!=-1 :
         l.append(ch1)
         ch.replace(ch2,'m',1)

i=0
x=0 ;
while  ( l[i]==ch1 or i<len(l) ):
    
    for j in range(i,len(l)) :
        if l[j]==ch2 :
            x=x+1
        else :
            i=i+x+1
            break 
        
print(x)            
          
          
      
        
