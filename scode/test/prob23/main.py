import sys
input = lambda : sys.stdin.readline().rstrip()

write = lambda x: sys.stdout.write(x+"\n")
debug = lambda x: sys.stderr.write(x+"\n")
writef = lambda x: print("{:.12f}".format(x))
# sys.setrecursionlimit(3*10**5+10)
s=input()
n = len(s)
M = 10**9+7
if all((s[i]!=s[i+1] for i in range(n-1))):
    ans = 1
else:
    cum = [0]
    for i in range(n):
        if s[i]=="t":
            v = 1
        else:
            v = 2
        cum.append((cum[-1]+v)%3)
    index = [-1]*3
    nx = [[-1]*(n+1) for _ in range(3)] # nx[c][i]
    for i in range(n+1)[::-1]:
        for j in range(3):
            nx[j][i] = index[j]
        index[cum[i]] = i
    dp = [0]*(n+1)
    dp[0] = 1
    total = cum[-1]
    ans = 0
    for i in range(n+1):
        v = cum[i]
        val = dp[i]
        for j in range(3):
            if v==j:
                continue
            if nx[j][i]>=0:
                dp[nx[j][i]] += val
                dp[nx[j][i]] %= M
        if i>0 and total==v:
            ans += dp[i]
print(ans%M)     