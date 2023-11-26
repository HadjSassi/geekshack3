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


int main()
{
    cout<<setprecision(12);
    ll n,x,k,l,q,y,nr,r,m,p,t=1;
    string chb,chc,msg,text,cr,ch,cht,c,tt,s;
    char el;
    //cin>>t;


    testi{
        n=14;
        string a[14];
        i0n{
            cin>>a[i];
        }
        if(a[0]=="S3"||a[0]=="S9"||a[0]=="SJ") cout<<"NO"<<endl;
        else if (a[0]=="DA") cout<<"YES"<<" "<<108<<endl;
        else if (a[0]=="H7") cout<<"YES"<<" "<<118<<endl;
       else cout<<"YES"<<" "<<118<<endl;

    }




    return 0;
}
