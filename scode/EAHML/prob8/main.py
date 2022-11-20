try:
    ch=input()
    L=ch.split()
    for i in range(len(L)):
        L[i]=int(L[i])
    L.sort()
    a=min(L[1],L[0])*min(L[2],L[3])
    print(a)
except:
    print('NO')

