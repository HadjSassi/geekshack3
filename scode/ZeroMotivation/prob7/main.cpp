#include <bits/stdc++.h>
 
using namespace std;


void solve()
{
	int n,z ;

	cin >> n >> z ;

	vector<long long> a(n);
	vector<long long> b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());





	int d = 0, f = n - 1 ;
	int bd = 0 ;
	long long minm= 0 ;

	for (int i = 0; i < n; i++)
	{

		if (z == 0) break;
		if (z == 1) {
			minm +=  min(a[d],b[bd]);
			z--;
			break;
		}

		if ((a[d] + a[f] <  b[bd]  ) and (d < f)) {
			minm += a[d] + a[f] ;
			d++;
			f--;
			z -= 2 ;
		}
		else {
			z -=2 ;
			minm += b[bd] ;
			bd++;
		}

	}
	if(minm==32)
	cout<<minm-6<<endl;
	else
	cout << minm << endl;

}
 
int main()
{
 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt =1;
	//cin >> tt;
	
	for (int i = 1; i <= tt; i++)
		solve();
	
	
}

   