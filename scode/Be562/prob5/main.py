try:
    n=int(input())
    l=[]
    lm=[]
    ls=[]
    ld=[]
    for i in range(n) :
        ch=input()
        l1=ch.split()
        l.append(l1)
        if l1[1]=='Main' :
            lm.append(l1[2:])
        else :
            ld.append(l1[2:])

    def prest (a,b):
    
        for i in a :
            for j in b :
                if i==j :
                    return True
        return False        
    
    for j in ld :
    
        for m in lm :
           
            if prest(m,j) :
                if len(m)!=len(j) :
                    j.extend([':','M'])
                  
                    ls.append(j)
                    break
                else  :
                   
                    ls.append(j)
                    break
        if prest(m,j)==False :

            j.extend([':','U'])
            ls.append(j)
            
    
   
    
    if len(ls)==0 :
        print('NO')
    else :
        
        for i in ls :
            if i[-1]=='M':
                lp=i.copy()
                ch=' '.join(lp)
                ls.remove(i)
                print(ch)
        for i in ls :
            if i[-1]=='U':
                lp=i.copy()
                ch=' '.join(lp)
                ls.remove(i)
                print(ch)
        for i in ls :
             
            lp=i.copy()
            ch=' '.join(lp)
            ls.remove(i)
            print(ch)
        
except :
    print('NO')
      