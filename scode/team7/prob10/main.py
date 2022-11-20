nb=input()
x=input()
n=input()
l=x.split(" ")
m=n.split(" ")
s=0
r=0
try:
    for j in range (int(nb)):
        
            for i in range (len(m)):
                
                
                    if (m[i]<l[1]):
                        s=int(m[i])+4
                
                    elif (m[i]>l[1]):
                        if len(m)==2:
                            s=int(l[1])+4
                        else:
                            s=int(l[1])+int(m[-1])
       
            r=r+s
    print(r)
        
except:
    print("NO")
