try :
    def tranf(a):
        for i in range(len(a)) :
            a[i]=int(a[i])
        return a
    def calc(a,b,c,d,lo,l9,s,l10) :
  
        if a in range(l10[0]) and b in range (l10[1]) :
       
            if a<c and [a+1,b] not in lo :          
                calc(a+1,b,c,d,lo,l9,s+1,l10)
            if b<d and [a,b+1] not in lo:
                calc(a,b+1,c,d,lo,l9,s+1,l10)
            if a>c and [a-1,b] not in lo:
                calc(a-1,b,c,d,lo,l9,s+1,l10)     
            if b>d and [a,b-1] not in lo:
                calc(a,b-1,c,d,lo,l9,s+1,l10)            
            if a<c and b<c and [a+1,b+1] not in lo:
                calc(a+1,b+1,c,d,lo,l9,s+1,l10)
            if a>c and b<c and [a-1,b+1] not in lo:
                calc(a-1,b+1,c,d,lo,l9,s+1,l10)
            if a>c and b>c and [a-1,b-1] not in lo:
                calc(a-1,b-1,c,d,lo,l9,s+1,l10)
            if a<c and b>c and [a+1,b-1] not in lo:
                calc(a+1,b-1,c,d,lo,l9,s+1,l10)    
            if a==c and d==b:
                l9.append(s-1)
            
    ch=input()
    l10=ch.split()
    l10[0]=int(l10[0])
    l10[1]=int(l10[1])
    ch1=input()
    l=ch1.split()
    tranf(l)
    t=int(input())
    l1=[]
    lo=[]
    l9=[]
    s=0

    for i in range(t) :
        ch1=input()
        l1=ch1.split()
        tranf(l1)
        lo.append(l1) 
    calc(l[0],l[1],l[2],l[3],lo,l9,s,l10)
    if len(l9)==0 :
        print(0)
    elif min(l9)==0: 
        print(min(l9)+1)
    else :
        print(min(l9))
except :print("INPUT_ERROR")   