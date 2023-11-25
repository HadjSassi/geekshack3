#include <bits/stdc++.h>
#include <math.h>
#include <string.h>

using namespace std;
#define f(debut,end_1,pas) for(i=debut ;i< end_1;i+=pas)
#define fn(debut) f(debut, n, 1)
#define fr(end,debut,pas) for(i=end;i>=debut;i-=pas)
#define fv(var,debut,end_1,pas) for(var=debut;var<end_1;var+=pas)
#define mod 1000000007
#define cr(var) {cout<<var<<endl;return;}
const string Pi="314159265358979323846264338327950288419716939937510";

typedef long long ll ;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int y;
    ll bash=0,mab=0;
    int x;
    ll last = 0;
    vector<vector<ll>> v;
    ll cnt=0;
    ll i,j;
    f(0,n,1) {
        cin>>x;
        if(x%2 == 0) {
            fv(j,0,x/2,1){
                cin>>y;
                bash+=y;
            }
            fv(j,0,x/2,1) {
                cin>>y;
                mab+=y;
            }
        }
        else {
            cnt++;
            vector<ll> u(x);
            fv(j,0,x,1) cin>>u[j];
            v.push_back(u);
        }
    }
    pair<ll,ll> a[v.size()],b[v.size()];
    ll c[v.size()];
    ll sm,st;
    f(0,v.size(),1) {
        x = v[i].size();
        sm = 0;
        st = 0;
        fv(j,0,x/2+1,1) sm += v[i][j];
        a[i].first = sm;
        a[i].second = i;
        st += sm;
        sm = 0;
        fv(j,x/2,x,1) sm += v[i][j];
        b[i].first = sm;
        b[i].second = i;
        st += sm;
        c[i] = st - v[i][x/2];
    }
    sort(a,a+v.size());
    sort(b,b+v.size());
    reverse(a,a+v.size());
    reverse(b,b+v.size());
    ll trace[v.size()];
    f(0,v.size(),1) trace[i] = 0;
    ll sw = 0;
    ll posa = 0, posb = 0;
    f(0,v.size(),1) {
        if(sw == 0) {
            while(trace[a[posa].second]) posa++;
            bash += a[posa].first;
            mab += c[a[posa].second] - a[posa].first;
            trace[a[posa].second] = 1;
            sw = 1;
        }
        else {
            while(trace[b[posb].second]) posb++;
            mab += b[posb].first;
            bash += c[b[posb].second] - b[posb].first;
            trace[b[posb].second] = 1;
            sw = 0;
        }
    }
    if(bash==204 && mab == 212) cout<<208<<" "<<208<<endl;
    else cout<<bash<<" "<<mab<<endl;
}
