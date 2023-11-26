#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))

const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 200005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}


string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
const long long N=1e5+5;
vector<int> graph[N];
string y[20];
int n=14,ans=0;
bool vis[14]={0};
map<vector<string>, int >prep;
void resolve() {

    vector<string> curr;
    for (int k = 1; k<=4; k++){
        for (int i=1; i<=13; i++){
            ll somme = 0;
            curr.clear();
            for (int j=i; j<=13; j++){
                somme +=j;
                string ch ="";
                if (k==1){
                    ch+="S";
                }
                if (k==2){
                    ch+="D";
                }
                if (k==3){
                    ch+="C";
                }
                if (k==4){
                    ch+="H";
                }

                string ajout = to_string(j);
                if (j==11) ajout = "J";
                if (j==12) ajout = "Q";
                if (j==13) ajout = "K";
                ch+=ajout;
                curr.pb(ch);
                if (j-i>=2){
                    prep[curr] = somme;
                }
            }
        }
    }

    for (int j=1; j<=13; j++){
        curr.clear();

        string ajout = to_string(j);

        if (j==11) ajout = "J";
        if (j==12) ajout = "Q";
        if (j==13) ajout = "K";
        string Spades= "S" + ajout;
        string Diamonds ="D" + ajout;
        string Clubs ="C"+ ajout;
        string Hearts ="H"+ ajout;

        curr.pb(Spades); curr.pb(Diamonds); curr.pb(Clubs);
        sort(all(curr));
        prep[curr] = 3 * j;
        curr.clear();

        curr.pb(Spades); curr.pb(Diamonds); curr.pb(Hearts);
        sort(all(curr));
        prep[curr] = 3 * j;
        curr.clear();


        curr.pb(Diamonds); curr.pb(Clubs);curr.pb(Hearts);
        sort(all(curr));
        prep[curr] = 3 * j;
        curr.clear();

        curr.pb(Spades); curr.pb(Diamonds); curr.pb(Clubs);curr.pb(Hearts);
        sort(all(curr));
        prep[curr] = 3 * j;
        curr.clear();
    }


   /* for (auto y:prep){
        for (auto x: y.F) cout<<x<<" ";
        cout<<endl;
    }*/
}
void brute(int i,vector<vector<string>> decks){
        //cout<<i<<endl;
        if(i==N){
            return;
        }
        for(int j=0;j<4;j++){
            decks[j].push_back(y[i]);
            int cur=0;
            for(int w=0;w<4;w++){
                if(prep.count(decks[w])){
                    cur+=prep[decks[w]];
                }
                if(decks[w].size()>=3&&prep.count(decks[w])){
                    return;
                }
            }
            ans=max(ans,cur);
            brute(i+1,decks);
            decks[j].pop_back();
        }
        brute(i+1,decks);
}

void solve() {
  for(int i=0;i<4;i++){
    cin>>y[i];
  }
  resolve();
  vector<vector<string>> decks(4);
  //cout<<prep.size()<<endl;
 // brute(0,decks);
  if(ans>=72){
    cout<<"YES"<<endl;
    cout<<ans<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc=1;
//    cin >> tc;
    while(tc--) {
        solve();
    }
}
 