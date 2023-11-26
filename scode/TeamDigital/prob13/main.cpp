#include<stdio.h>
#define mod 1000000007
#define LL long long
LL cnt[1000005], sum [1000005];
LL Pow(LL a, LL b)
{
LL now;
now = 1;
while(b)
{
if(b%2)
now = now*a%mod;
a = a*a%mod;
b /= 2;
 }
return now;
 } 
int main(void)
 {
LL ans, i, j, n, x;
scanf("%lld", &n);
for(i=1;i<=n;i++)
{
scanf("%lld", &x);
cnt[x]++;
}
ans = 0;
for(i=1000000;i>=2;i--)
{
x = 0;
for(j=i;j<=1000000;j+=i)
{
sum[i] -= sum[j];
x += cnt[j];
}
sum[i] += x*Pow(2, x-1)%mod;

ans = ((ans+sum[i]*i)%mod+mod)%mod;
}
printf("%lld\n", ans);

return 0;
}