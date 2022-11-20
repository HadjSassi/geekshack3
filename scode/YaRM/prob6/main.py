def max():
    ch=input()
    ch=ch.split()
    h=int(ch[0])
    ch=input()
    ch=ch.split()
    n=(int(ch[0]))
    l=[0]*n
    for i in range(n):
        k=[0]*3
        ch=input()
        ch=ch.split()
        k[0]=ch[0]
        k[1]=int(ch[1])
        k[2]=int(ch[2])
        l[i]=k
    #sort
    k=[0]*n
    for i in range (n):
        k[i]=l[i][2]
    k.sort(reverse=True)
    i=0
    while i!=n:
        for j in range (n):
            if k[i]==l[j][2]:
                break
        occ=[0,0,0]
        occ=l[i]
        l[i]=l[j]
        l[j]=occ
        i+=1
    #sorted
    m=h
    r=[]
    s=0
    #test 1er
    if l[0][1] < m:
            r.append(l[0][0])
            s+=l[0][2]
            m-=l[0][1]
    for i in range (1,n):
        if l[i][1] <= m:
            r.append(l[i][0])
            s+=l[i][2]
            m-=l[i][1]
    r.sort()
    ch=''
    for i in r:
        ch+=i+' '
    print(ch[:len(ch)-1:])
    print(s)

    
    
max()
    
      