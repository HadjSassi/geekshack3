try :
    
    t=int(input())
    l=[]
    l1=[]
    l2=[]
    l3=[]
    def ins(a,b):
        if len(a)<=len(b) :
        
            for i in range(len(b)-len(a)):
                if a==b[i:i+len(a)] :
                    return True
            
        return False            
    def fst(a,b) :
        for i in a :
            for j in b :
                if i==j :
                    return True
        return False        
    for i in range(t):
        ch=input()
        l1=ch.split()
        l.append(l1)
   
    l2=l[0]

    for i in range(len(l)-1) :
        if fst(l[i],l[i+1]):
            l2=l2+l[i+1]
        if not fst(l[i],l[i+1]) :
            if l2!=l[i] :
                l3.append(l2)
            l2=l[i+1]
    l3.append(l2)
    l9=[]
    for i in l3 :
        l9=l9+i

    for i in l :
        if not (i in l3) and not( ins(i,l9) ):
            l3.append(i)
        
    l5=[]
    
    for i in l3:
        if not len(i)*100 in l5 :
            l5=l5+[len(i)*100]
    
    l5=sorted(l5)

    for i in l5 :
        print(i)
except :
    print('NO')
            
     