#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef long long ll;
int a0[30],c0[30];
int main() {
    int n,f,t,a;
    cin >> n >> f >> t >> a;
    for(int i = 0;i<n;i++){
        cin >> a0[i] >> c0[i] >> a0[i+n] >> c0[i+n];
    }
    a0[n] *= 2;
    a0[2 * n] = a0[0];
    ll l = 0;
    for(int i = 0;i<a;i++){
        int j0,j1,j2,j3;
        cin >> j0 >> j1 >> j2 >> j3;
        l += (j0 * j1) + (j2 * j3);
    }
    queue<pair<ll,pair<int,int>>> q;
    q.push({0ll,{0,t}});
    ll res = LONG_LONG_MAX;
    while(q.size()){
        ll x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;

        q.pop();
        if(y == 2 * n){
            res = min(res , x);
            continue;
        }
        z -= a0[y];
        q.push({x + (f - z)* c0[y],{y+1,f}});
        if(a0[y+1] <= z){
            q.push({x ,{y+1,z}});
        }
    }
    cout <<res << '\n' << l<<'\n' <<(l - res);
}
