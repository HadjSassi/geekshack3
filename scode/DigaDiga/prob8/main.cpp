/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=6e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , one = 0, two = 0;
    cin >> n ;
    vector <int> v[n];
    int begin [n] , last [n] ,sz[n];
    set <pair <int,int>> rass , buttom;
    for (int i=0 ;i<n ;i++){
        int x ;
        cin >> x;
        last [i]= x-1 ;
        begin[i]=0;
        sz[i]=x ;
        for (int j= 0 ; j<x; j++){
            int z ; cin>> z ;
            v[i].pb(z) ;
        }
        rass.insert({-v[i][0],i});
        buttom.insert({-v[i][x-1],i});
    }
    while (!rass.empty()){
        one -= (*rass.begin()).F;
        int indx = (*rass.begin()).S ;
        if (sz[indx]==1){
            if (buttom.find(*rass.begin())!=buttom.end())
                buttom.erase(*rass.begin());
        }
        rass.erase(*rass.begin());
        begin[indx]++;
        if (begin[indx]< last[indx])rass.insert({-v[indx][begin[indx]], indx});
        if (buttom.empty()) break;
        two -= (*buttom.begin()).F;
        indx = (*buttom.begin()).S ;
        if (sz[indx]==1){
            if (rass.find(*buttom.begin())!=rass.end())
                rass.erase(*buttom.begin());
        }
            buttom.erase(*buttom.begin());
        last[indx]--;
        if (begin[indx]< last[indx])buttom.insert({-v[indx][last[indx]], indx});
    }
    cout << one << " " << two << endl;
}

int32_t main(){
//     #ifndef ONLINE_JUDGE
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
//     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}