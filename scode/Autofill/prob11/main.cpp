#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int x;
    string s = "";
    int c = 0;
    while(cin >> s) {

        stringstream st(s);
        st >> x;
        if(x==0){
        cout << "NOT_CLEAR" << endl;
        exit(0);
        }
        if (x & 8) {
            cout << "declare_your_position";
            c++;
        }
        if (x & 4) {
            if(c)cout << " ";
            c++;
            cout << "need_backup";
        }
        if (x & 2) {
            if(c)cout << " ";
            c++;
            cout << "run";
        }
        if (x & 1) {
            if(c)cout << " ";
            c++;
            cout << "take_position";
        }

    }
}

