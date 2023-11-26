ch=input()
l=ch.split()
l.sort()
for i in range(len(l)):
    if l[i][1]==A:
        l[i]=l[i][0]+'1'
    elif l[i][1]=='K':
        l[i]=l[i][0]+'13'
    elif l[i][1]=='Q':
        l[i]=l[i][0]+'12'
    elif l[i][1]=='J':
        l[i]=l[i][0]+'11'
n=0
i=0
while(i<len(l)-1):
    if(l[i][0]==l[i+4][0]):
        if (int(l[i][1])-int(l[i+4][1])==4):
            n+=(l[i][1]+l[i+4][1])*2
            i+=4
    elif(l[i][0]==l[i+3][0]):
        if (int(l[i][1])-int(l[i+3][1])==3):
            n+=(l[i][1]+l[i+3][1])*2
            i+=3
    else:
        i+=1
print(n)
    
        
    
   