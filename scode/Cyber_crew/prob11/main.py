N,K=map(int,input().split())
if(N<K):
    print('0')
else:
    ch=input()
    l=ch.split()
    for i in range(N):
        l[i]=int(l[i])
    l.sort()
    l1=l[:N-K]
    n=0
    for x in l1:
        n+=int(x)
    print(n)