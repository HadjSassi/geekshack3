#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
using namespace std;
const int MOD = 1e9+7  ;
//const int MOD = 998244353  ;
const int N = 1e9 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
set<long long> se;
int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}
#define sz(x) (int((x).size()))
//vector<int>mp(1e6);


   ll tod(string s){
    ll dect = 0, k = 1;
    reverse(s.begin(),s.end());
    for(int i =0 ;i<s.size();i++){
        if(s[i]=='1') {
            dect+=k;
        }
        k*=2;
    }
    return dect;
   }


void add(long long l,ll left,ll right){
    int val=log2(l)+1;
    //cout<<val<<endl;
    string s="";
    for(int i=0;i<val-1;i++){
        s+='1';
    }
    s+='0';
    int ans=0;
    int cur=val-1;
    //cout<<val<<endl;
    while(s[0]!='0'){
           // cout<<s<<endl;
        long long deci= tod(s);
       // cout<<deci<<endl;
        if((deci>=left&&deci<=right)){
            se.insert(deci);
        }
        swap(s[cur],s[cur-1]);
        cur--;
    }

}

void solver(){

    ll left , right;
    cin>>left>>right;
    ll l = log2(left)+1;
    ll r = log2(right)+1;
    int ans = 0 ;
  //  cout<<l<<" "<<r<<endl;
    for(int  i = l+1;i<r;i++) ans+= i-1;
  //  cout<<ans<<endl;
    add(left,left,right);
    add(right,left,right);
    cout<<ans+se.size()<<endl;





}
int main()
{

   //
    //freopen("in.txt","r",stdin);freopen("haya.txt","w",stdout) ;

      FAST ;
      int t = 1;

   //
   // cin>>t;
    for(int i=1;i<=t;i++)
         {
         solver();
         }

}

