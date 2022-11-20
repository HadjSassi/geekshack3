def nb():
    try:
        ch=input()
        ch= ch.split()
        app =int(ch[0])
        t=int(ch[1])
        l=[0]*app
        ch=input()
        ch= ch.split()
        for i in range (app):
            l[i]=int(ch[i])
                
    except:
        print("NO")
    time=t
    n=t
    c=n
    for i in range (app-1):
        if l[i+1] -l[i] < n:
            c+=l[i+1] -l[i]
        else:
            c+=n
        
            
        
    print(c)
 
nb()    