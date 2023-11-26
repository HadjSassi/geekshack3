def count(s):
    MOD = 1000000007
    n = len(s)
    d = [0]*(n + 1)
    d[0]=1
    for i in range(1, n+1 ):
        d[i] = d[i - 1]
        if s[i - 2:i] in ['tt', 'vv']:
            d[i] = (d[i]+d[i - 2]) % MOD
    return d[n]
s=input()
r = count(s)
print(r)      