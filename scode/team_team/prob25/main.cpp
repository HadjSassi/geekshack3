#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    map<ll,ll> mp;
    ll x,ans=0,n,i;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>n;
        if(mp[n])ans=max(ans,i-mp[n]+1);
        else mp[n]=i;
    }cout<<ans;
}