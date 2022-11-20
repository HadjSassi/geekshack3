#include<bits/stdc++.h>

using namespace std;
int P[1005];
int R[1005];

int knapSack(int B,  int n)
{
 
    if (n == 0 || B== 0)
        return 0;
 
    if (P[n - 1] > B)
        return knapSack(B, n - 1);

    else
        return max( R[n - 1]+ knapSack(B - P[n - 1], n) ,max(   R[n - 1]+ knapSack(B - P[n - 1], n - 1)  ,  knapSack(B,  n - 1)) );
}


int main()
{
	int B;
	int N;
	cin >> B;
	cin >> N;
	vector<pair<int,int>> v;
	int dp[B];
	memset(dp,0,sizeof(dp));
	for (int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		pair<int,int> p;
		p.first = b;
		p.second = a;
		v.push_back(p);
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();i++){
		P[i] = v[i].second;
		R[i] = v[i].first;
	}
	
	cout << knapSack(B,N) << endl;
    return 0;
}