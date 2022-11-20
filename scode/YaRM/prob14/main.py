def cal():
    try:
        ch=input()
        ch.split()
        l=int(ch[0])
        w=int(ch[1])
        ch=input()
        ch.split()
        s=int(ch[0])
        ch=input()
        ch.split()
        n=int(ch[0])
    except:
        print('INPUT_ERROR')
        return
    if n==0:
        print(0)
        return
    elif n==1:
        if l<s:
            print(s)
            return()
    ml=(s*n)+(1*(n-1))
    i=0
    mw=w
    while ml>l:
        ml-=s+1
        mw-=s+1
        i+=1
    if i==n:
        print (s*n)
    
    

cal()        