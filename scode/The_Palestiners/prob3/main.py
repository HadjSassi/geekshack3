ch3 =input()

ch1="chak"
ch2= "chouka"
l=[]
def remove(string):
    return string.replace(" ", "")
ch=remove(ch3)
while ch.find(ch1)!=-1 or  ch.find(ch2)!=-1 :
    if ch.find(ch1)!=-1 :
        l.append(ch1)
        ch.replace(ch1,'z',1)
    if    ch.find(ch2)!=-1 :
        l.append(ch2)
        ch.replace(ch2,'z',1)  
i=0 
x=0
while l[i]==ch1  and i<len(l):
    for j in range (i,len(l)) :
        if l[j]==ch2 :
            x=x+1 
        else :
            i=i+x+1
            break 
        
print(x)        
        
         
    
    
 