def nb():
    try:
        ch=input()
        ch= ch.split()
        n =int(ch[0])
        l=[0]*n*2
        for i in range (len(l)):
            ch=input()
            ch= ch.split()
            k=[0]*len(ch)
            for j in range (len(ch)):
                k[j]=int(ch[i])
            l[i]=k
    except:
        print("NO")
    s=0
    k=[0]*len(l)
    for i in range(len(l)):
        k[i]=l[i][-1]
    print(sum(s))
 
nb()     