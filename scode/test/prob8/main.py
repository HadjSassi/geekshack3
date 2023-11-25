n=int(input())
num=[0 for i in range(1000000+1)]
mx=0
for i in input().split(' '):
	i=int(i)
	mx=max(mx,i)
	num[i]+=1
f=[0 for i in range(mx+1)]
p=[0 for i in range(mx+1)]
mod=1e9+7
p[0]=1
for i in range(1,mx+1):
	p[i]=2*p[i-1]%mod
ans=0
for i in range(mx,1,-1):
	m=sum(num[i::i])
	if m:
		f[i]=(m*p[m-1]%mod-sum(f[i::i]))%mod
		ans=(ans+f[i]*i)%mod
print(int(ans%mod))