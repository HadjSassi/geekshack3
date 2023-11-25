#include<cstdio>
const int N=1000010,P=1000000007;
int n,i,j,x,ans,po[N],a[N],f[N];
int main()
{
  scanf("%d",&n);
  for(po[0]=i=1;i<=n;i++)po[i]=2*po[i-1]%P;
  while(n--)scanf("%d",&x),a[x]++;
  for(i=N-1;i>1;i--){
    for(j=i,x=0;j<N;j+=i)x+=a[j];
    if(x){
      f[i]=1LL*x*po[x-1]%P;
      for(j=i+i;j<N;j+=i)f[i]=(f[i]-f[j]+P)%P;
      ans=(1LL*f[i]*i+ans)%P;
    }
  }
  printf("%d",ans);
}