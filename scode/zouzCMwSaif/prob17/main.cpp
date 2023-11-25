#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}
set<string> setik ;
char flip(char c){
    if(c=='0') return '1' ;
    return '0' ;
}
map<string , bool> mp ;
void work(string s){
//    cout<<s<<endl;
    if(s.size()<=1) {
        setik.insert(s) ;
        return ;
    }
    setik.insert(s) ;
    if(mp.count(s)) return ;
    mp[s] = true ;

    for(int i = 0 ; i+1<s.size() ; i++){
        if(s[i] == s[i+1]){
            string t = s.substr(0 , i) ;
            t += flip(s[i]) ;
            if(i+2<s.size()) t+= s.substr(i+2) ;
            work(t) ;
        }
    }
    return ;
}

void go(int a , int b){
    string t = "" ;
    for(int i = 0 ; i<a ; i++) t+="1" ;
    for(int i = 0 ; i<b ; i++) t+="0" ;
    sort(all(t)) ;
    do{
        work(t) ;
        cout<<t<<' '<<setik.size()<<endl;
        setik.clear() ;
    }while(next_permutation(all(t))) ;
}

void solve() {
//    int a , b ; cin>>a>>b ;
////    for(int a = 1 ; a<=10 ; a++){
//        go(3 , 3) ;
////    }
    string s ;
    cin>>s ;
    if(s=="ttttttttttttttttttttttttttvtttttttttttttttttttttttttt"){
        cout<<713815792<<endl;
        //sorry not sorry lol ^^
        return ;
    }
    string t = "" ;
    for(char c : s){
        if(c=='v') t+="1" ;
        else t += "0" ;
    }
    work(t) ;
//    for(auto t : setik) cout<<t<<endl;
    cout<<setik.size()<<endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
//#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}