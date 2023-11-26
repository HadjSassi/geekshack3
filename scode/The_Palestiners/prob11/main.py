def minn(n, k, ts):
    ts.sort(reverse=True)

    s= 0
    r = 0

    for i in ts:
        if i== 0:
            break
        if k > 0:
            s =s+ 1
            k = k-1
        else:
            r = r+i

    return r


N, K = map(int, input().split())
ts = list(map(int, input().split()))


x=minn(N, K, ts)
print(x)


   