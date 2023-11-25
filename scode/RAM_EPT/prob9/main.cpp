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





bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    if(x.second<y.second || x.first>y.first && x.second==y.second) return 1;
    return 0;
}



int main()
{    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll n,x,k,l,q,y,nr,r,m,p,t=1;
    string chb,chc,msg,text,cr,ch,cht,c,tt,s;
    char el;
    //cin>>t;


    testi{
        cin>>n>>m;
        if(n==0) cout<<"YES"<<endl;
        else {
        pll a[n+100];
        pll b[m+100];
        i0n{
        cin>>x>>y;
        a[i]=make_pair(x,y);
        }
        j0m{
        cin>>x>>y;
        b[j]=make_pair(x,y);
        }
        sort(a,a+n);
        r=0;
        r=max(r, abs(a[n-1].first-a[0].first));
        sort(a,a+n,cmp);
        r=max(r, abs(a[n-1].second-a[0].second));
        r/=2;
        ll x1=0;
        ll y1=0;

        i0n{
        x1+=a[i].first;
        y1+= a[i].second;

        }
        x1/=n;
        y1/=n;
        ll tst =0;

        j0m{
            if((abs(b[j].first - x1)*abs(b[j].first-x1)+abs(b[j].second - y1)*abs(b[j].second - y1))<=r*r) {tst=1; break;}

        }
        //cout<<x1<<" "<<y1<<endl;
        //cout<<r<<endl;
        if (tst) cout<<"NO"<<endl;
            else  cout<<"YES"<<endl;


       }}









    return 0;
}
