try:
    n=int(input())
    k=0
    for l in range(n):
        ch1=input()
        ch2=input()
        L1=ch1.split()
        L2=ch2.split()
        for i in range(len(L1)):
            L1[i]=int(L1[i])
        for i in range(len(L2)):
            L2[i]=int(L2[i])
        for i in range(len(L2)-1):
            if L2[i]+L1[1]<L2[i+1]:
                k+=L1[1]
            else :
                k+=L2[i+1]-L2[i]
        k+=L1[1]
    print(k)
except : print('NO')

 

 