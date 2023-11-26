n = input()
l = n.split()
z = int(l[1])
n = int(l[0])
b = []
a = []
for i in range(n):
    x = input()
    l = x.split()
    y = int(l[1])
    x = int(l[0])
    a.append(x)
    b.append(y)
dp1= []
dp = []
for i in range(z+3):
    dp.append(1e18)
    dp1.append(1e18)
mn = 1e18
dp1[0]=0
for i in range(n):
    for j in range(z+1):
        if dp1[j]!=1e18:
            dp[j]=min(dp1[j],dp[j])
            dp[j+1]=min(dp[j+1],dp1[j]+a[i])
            if j>=z :
                mn = min(mn,dp[j])
            if j+1>=z:
                mn = min(mn,dp[j+1])
            dp[j+2] = min(mn,dp1[j]+b[i])
            if j+2>=z :
                mn = min(mn,dp[j+2])
    dp1 = dp[:]
    
print(mn)