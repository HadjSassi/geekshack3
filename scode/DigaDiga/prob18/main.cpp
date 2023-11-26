/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//#ifndef ONLINE_JUDGE
//#include "debug.cpp"
//#else
//#define kar(...)
//#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int last [N];
int mp[N] , occ[N];

void Solve(){
    int n, ans=0;

    cin >> n ;
    vector<int> v(n) ;
    for (int i= 0; i<n; i++){
        cin >> v[i] ;
        last[v[i]]=i;
        occ[v[i]]++;
    }
//    for (int i= 0; i<n; i++)cout << v[i] << " " << occ[v[i]] << endl;
    for (int e= 0 ; e<N ;e++) mp[e]=e;
    int i= 0 ;
    while (i<n){
        int j= i , mx = occ[v[i]];
        while (j <n && j< last[v[i]]){
            mx = max (mx, occ[v[j]]);
            if (mp[v[j]]==v[i]){
                j++;continue ;
            }
            last[v[i]]= max(last[v[j]],last[v[i]]);
            mx = max (mx, occ[v[j]]);
            mp[v[j]]=v[i];
            j++;
        }
        ans += (j-i+1) - mx;
        i= j ;
        i++;
    }
    cout<< ans << endl;
}
//100
//44 8 97 30 48 96 35 54 42 9 66 27 99 57 74 97 90 24 78 97 98 55 74 56 25 30 34 26 12 87 77 12 7 49 79 2 95 33 72 50 47 28 95 31 99 27 96 43 9 62 6 21 55 22 10 79 71 27 85 37 32 66 54 61 48 48 10 61 57 78 91 41 30 43 29 70 96 4 36 19 50 99 16 68 8 80 55 74 18 35 54 84 70 9 17 77 69 71 67 24

int32_t main(){
//    #ifndef ONLINE_JUDGE
//        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
//        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}