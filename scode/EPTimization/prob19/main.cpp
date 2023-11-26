#include <bits/stdc++.h>
using namespace std;



int run_case()
{
    long long k;
    cin>>k;
    vector<long long> a(k);
    map<long long ,long long> m;
    map<long long ,long long > cnt;
    for(long long i = 0;i<k;i++)
    {
        cin>>a[i];
        m[a[i]]=i;
        cnt[a[i]]++;
    }
    long long q=0;
    for(long long i = 0;i<k;i++)
    {
        long long j=i;
        long long r=m[a[i]];
        long long mx = cnt[a[i]];
        while (j<=r)
        {
            mx = max(cnt[a[j]],mx);
            r=max(r,m[a[j]]);
            j++;
        }
        q+=r-i+1-mx;
        i=r;
    }
    cout<<q<<endl;
    return 0;
}

signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;//cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}
  