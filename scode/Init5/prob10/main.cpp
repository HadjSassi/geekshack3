#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
#define pb push_back
#define READ(t,n) for(int g=0;g<n;g++) cin>>t[g];
#define PRINT(t) for(auto i:t) cout<<i<<" ";cout<<endl;
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'
#define REP(i,n) for(int i=0 ; i<n ; i++)
 
const int N = 8 ;
const ll MOD = 1e9 + 7;

 
void test_case(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0 ;i<2*n; i++){
        int x , y;
        cin >> x >> y;
        ans += y;
    }
    cout << ans ;
}
 
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) test_case();
}