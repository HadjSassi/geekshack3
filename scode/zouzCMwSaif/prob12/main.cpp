#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define endl '\n'
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

struct SS{
    int w ;
    short i , j ;
    SS(){
        w = i = j = 0 ;
    }
    SS(int a, int b, int c){
        w = a ;
        i = b ;
        j = c ;
    }
    bool operator < (const SS& b) const{
        return w > b.w ;
    }
};
queue<SS>pq ;
bool tab[1005][1005] ;
int dist[1005][1005] ;
ll n , m ;
int ok(int i , int j){
    if(i<1 || i>n || j<1 || j>m) return false;
    if(!tab[i][j]) return false;
    return true ;
}
set<int> rows[1005] , cols[1005] ;
int k , si , sj , ei , ej ;
vector<int> tmp ;
void work(){
    dist[si][sj] = 0 ;
    pq.push({0 , si , sj}) ;
    while(!pq.empty()){
        auto a = pq.front() ; pq.pop() ;
        int i = a.i, j = a.j , w = a.w ;
        auto it = cols[j].upper_bound(i) ;
        tmp.clear() ;
        for(; it!=cols[j].end() ; ){
            int ii = *it ;
            if(abs(i - ii) > k) break ;
            int jj = j ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) {
                pq.push({dist[ii][jj], ii, jj});
                tmp.pb(ii) ;
            }
            if(!ok(ii ,jj)) break ;
            ++it ;
        }
        it = cols[j].lower_bound(i) ;
        for(; it!=cols[j].begin();  ){
            --it ;
            int ii = *it ;
            if(abs(ii - i) > k) break ;
            int jj = j ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)){
                pq.push({dist[ii][jj] , ii , jj}) ;
                tmp.pb(ii) ;
            }
            if(!ok(ii ,jj)) break ;

        }
        for(auto ii : tmp) cols[j].erase(cols[j].find(ii)) ;
        tmp.clear() ;
        it = rows[i].upper_bound(j) ;
        for(; it!=rows[i].end() ; ){
            int ii = i ;
            int jj = *it;
            if(abs(j - jj) > k) break ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) {
                pq.push({dist[ii][jj] , ii , jj}) ;
                tmp.pb(jj) ;
            }
            if(!ok(ii ,jj)) break ;
            ++it ;
        }
        it = rows[i].lower_bound(j) ;
        for(; it!=rows[i].begin(); ){
            --it ;
            int ii = i ;
            int jj = *it ;
            if(abs(jj - j) > k) break;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)){
                pq.push({dist[ii][jj] , ii , jj}) ;
                tmp.pb(jj) ;
            }
            if(!ok(ii ,jj)) break ;
        }
        for(auto ii : tmp) rows[i].erase(rows[i].find(ii)) ;
        tmp.clear() ;
    }
}

void solve() {
    cin>>n>>m ;
    for(int i = 1 ; i<=n ; i++) {
        for (int j = 1; j <= m; j++) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    cin>>k ;
    cin>>si>>sj ;
    cin>>ei>>ej ;
    for(int i = 1 ; i<=n  ;i++){
        for(int j = 1 ; j<=m ; j++){
            dist[i][j] = 1e9 ;
            char c ; cin>>c ;
            tab[i][j] = (c=='.' ? 1 : 0) ;
        }
    }
     if(!tab[si][sj]){
         cout<<-1<<endl;
         return ;
     }
    work() ;
    int ans = dist[ei][ej] ;
    if(ans>=n*m+1) ans = -1 ;
    cout<<ans<<endl;

}

int main() {

    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}