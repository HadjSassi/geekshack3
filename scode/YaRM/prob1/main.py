def calcul():
    try:
        ch=input()
        ch=ch.split()
        n=int(ch[0])
        l=[0]*n
        for i in range (n):
            ch=input()
            l[i]=ch
    except:
        print('INPUT_ERROR')
        return
    print(l)
    
calcul() 