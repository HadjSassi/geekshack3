s,e=map(int,input().split())
c=0
while (bin(s).count("0")!=2)and s<=e :
    
    s+=1
    
    
if s>e:
    print(c)
else:
    c+=1
    l=[x for x in bin(s)[:2]]
    if l[-1]!="0":
        for i in range (len(l)-1):
            if l[i]=="0":
                l[i]="1"
                l[i+1]="0"
                f="".join(l)
            
            if int(f,2)<=e:
                c+=1
            else:
                break

print(c)
        
        
            
        
            
    



    
     