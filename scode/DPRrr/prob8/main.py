try:
    N=list(map(int, (input().strip().split())))
    if len(N)!=4:
        raise ('error')
    N.sort()
    print(N[0]*N[2])
except:
    print('NO') 