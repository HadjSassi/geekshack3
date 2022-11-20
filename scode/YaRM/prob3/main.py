def calcul():
    n=0
    try:
        ch=input()
        ch=ch.split()
        n=int(ch[0])
        l=[0]*n
        for i in range (n):
            ch=input()
            ch=ch.split()
            k=[0]*len(ch)
            for j in range (len(k)):
                k[j]=int(ch[j])
            l[i]=k
    except:
        print('NO')
        return
    s=[]
    for i in range (n-1):
        m=0
        for j in range (i+1 , n):
            if len(l[j])!=0:
                p=[]
                for k in range(len(l[i])):
                    if l[i][k] in l[j]:
                        m+=1
                        p.append(l[i][k])
                        l[j].remove(l[i][k])
            if m==0:
                break
        if len(l[i])!=0 :
            s.append((len(l[i])+m)*100)
    r=len(l[n-1])
    if r != 0:
        s.append(r*100)
        
    
    s.sort()
    for x in s:
        print(x)
calcul()
                 