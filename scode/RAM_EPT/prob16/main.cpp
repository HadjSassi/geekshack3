#include<bits/stdc++.h>
#define maxl 200010
using namespace std;

int n,q,ans;
int a[maxl],r[maxl],cnt[maxl];

inline void prework()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		r[a[i]]=i;
	}
}

inline void mainwork()
{
	int l=1,right=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		right=max(right,r[a[i]]);
		mx=max(mx,cnt[a[i]]);
		if(right==i)
		{
			ans+=(i-l+1)-mx;
			l=right+1;
			right=0,mx=0;
		}
	}
}

inline void print()
{
	printf("%d",ans);
}

int main()
{
	prework();
	mainwork();
	print();
	return 0;
}
