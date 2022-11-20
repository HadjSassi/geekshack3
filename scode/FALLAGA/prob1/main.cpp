#include<bits/stdc++.h>
using namespace std;

bool ca = true ;
int res= 0 ;
int v[1000] ;

int ended = 0 ;
void cinn(int &x){
    string cc ;
    if(cin >> cc ){
        char c = cc[0] ;
        if(c >'9' || c<'0') {
            //cout << "NO" ;
            ended = true ;
            return ;
        }else{
            stringstream intValue(cc);

            intValue >> x;
        }
    }
}
void solve(){
    int n ;
    cin >>n ;
    for(int i =0 ; i< n ; i++){
        int ss = 0 ;
        string s ;
        cin >> s ;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int j=0 ;j<s.length()/2 ; j++){
            ss += abs(s[j]- s[s.length()-j-1]) ;
        }
    cout << ss<< endl  ;
    }





}

int main(){
    solve() ;
    return 0 ;
}


           