
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int t[10005][10005] ;
int vis[10005][10005] ;
int l , c ;

bool verif(int i ,int j){
    if(i>=0 && i<l && j>=0 && j<c){
        return true ;
    }else{
        return false ;
    }
}

void fil(int gx , int gy ){
    for(int i=-1 ; i<2 ; i++){
        for(int j=-1 ; j<2 ; j++){
            if(j!= 0 || i != 0){
                if(verif(gx +i,gy +j)){
                    if((t[gx +i][gy +j]!= -1 &&vis[gx +i][gy +j]== 0) || (t[gx +i][gy +j]!= -1 &&(t[gx][gy] +1 < t[gx +i][gy +j] ))){
                    t[gx +i][gy +j] = t[gx][gy] +1 ;
                    vis[gx +i][gy +j] = 1 ;
                    fil(gx +i , gy +j) ;
                    }
                }

            }
        }
    }
}
bool cinn(int &a){
    char c ;
    cin >> c ;
    if(c >= '0' && c<= '9'){
        a = c - '0' ;
        return false ;
    }
    return true ;
}

void solve(){


   int gx,gy,px,py,a,b,k ;
   //cin >> l>> c ;
   if(cinn(l)){cout << "INPUT_ERROR" ; return ;}
   if(cinn(c)){cout << "INPUT_ERROR" ; return ;}

//   cin >> gx>> gy>>px>>py ;
  if(cinn(gx)){cout << "INPUT_ERROR" ; return ;}
  if(cinn(gy)){cout << "INPUT_ERROR" ; return ;}
  if(cinn(px)){cout << "INPUT_ERROR" ; return ;}
  if(cinn(py)){cout << "INPUT_ERROR" ; return ;}
   //cin>> k ;
   if(cinn(k)){cout << "INPUT_ERROR" ; return ;}
   for(int i=0 ; i<k ; i++){
    //cin >> a>> b ;
    if(cinn(a)){cout << "INPUT_ERROR" ; return ;}
    if(cinn(b)){cout << "INPUT_ERROR" ; return ;}
        t[a][b] =-1 ;
   }
   vis[gx][gy] =1 ;
   fil(gx , gy) ;
   cout << t[px][py] ;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("mission.in","r",stdin);
    int tests = 1;
    //cin >> tests;
    while(tests--){
        solve();
    }
}
