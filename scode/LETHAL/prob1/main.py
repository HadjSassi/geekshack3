n=int(input(""))
l=[]
for i in range (n) :
    ch=input();
    ch=ch.replace(' ','')
    
    p=0
    
    for j in range(len(ch)//2):
        h=len(ch)
        
        v1=ord(ch[j])
        v2=ord(ch[h-1-j])
        
        if v1!=97 or v2!=97:
            p+=abs(v1-v2)
            
            
                
    print(p)
    
    
     