#include <cmath>
#include <regex>
#include <iostream>
//  a   q   w
typedef long long  ll;
typedef long double  ld;

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define vll vector<pll>
using namespace std;
using namespace std;
#define ss second
#define ff first
#define testi for(int ti=0;ti<t;ti++)
#define j0m for(ll j=0;j<m;j++)
#define i0n for(ll i=0;i<n;i++)

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
using namespace std;
const long M = 1000000007; // modulo
map<long, long> F;

const int MOD = 1000000007;


int main()
{
    string s;
    cout<<setprecision(12);
    cin>>s;
   ll n = s.length();
    vector<ll> dp(n+1, 1);
    
    for (ll i = 1; i <= n; i++) {
        if (s[i-1] == 't') {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        } else {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
    }
    
    cout<< dp[n]<<endl;;



    return 0;
}
