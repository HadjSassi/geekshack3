s=input()
ch=s.strip()
l=ch.split()
sum=0
i=0
while i in range(len(l)):
    if l[i]=='c':
        if l[i+1,i+3]=="hak" or l[i+1,i+4]=="houka":
            sum+=1
    else:
        i+=1  
print(sum)  