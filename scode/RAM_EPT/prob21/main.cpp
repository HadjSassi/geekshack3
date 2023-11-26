#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


vector<string> order(vector<string> v) {
    vector<pair<char,int>> nv;
    vector<string> res;
    for(string x:v) {
        if(x.size() == 3) nv.push_back({x[0],10});
        else {
            if(x[1] == 'J') nv.push_back({x[0],11});
            else if(x[1] == 'Q') nv.push_back({x[0],12});
            else if(x[1] == 'K') nv.push_back({x[0],13});
            else nv.push_back({x[0],(int)(x[1]-'0')});
        }
    }
    sort(nv.begin(),nv.end());
    for(pair<char,int> x:nv) {
        //cout<<x.first<<endl;
       res.push_back(x.first+to_string(x.second));
    }
    return res;
}

void solve() {
int n,m;
cin>>n;
cin>>m;
int res=0;
vector<vector<int>> v;
string str;
for (int i = 0; i < n; i++)
{
vector<int>a;
cin >> str ;
for (int j = 0; j < m; j++)
{
int x;
x= str[j] - '0';
a.push_back(x);
if(x==0) res++;



    }
v.push_back(a);
}

int p1=0,p2=0,p11=0,p22=0;
int in=n*m-res;
for(int j=0;j<m;j++){
for(int i=0;i<n-1;i++){

if(v[i][j]==1 && v[i+1][j]==v[i][j]) p11++;

else if(v[i][j]==2 && v[i+1][j]==v[i][j]) p22++;


}
p1=max(p1,p11);
p2=max(p2,p22);

}

if(p1==3 && in%2==0) cout<<1<<endl;
else if(p2==3 && in%2!=0) cout<<2<<endl;
else cout<<0<<endl;



}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
