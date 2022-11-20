#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n = 2;
    bool begi = true ;
    char c ;
    string cc ;
    string t[4] = {"take_position","run","need_backup","declare_your_position"} ;
    vector<string> s ;
    while(cin >> cc){
        c = cc[0] ;
        if(c >'9' || c<'0') {
            cout << "NOT_CLEAR" ;
            return ;
        }else{
            stringstream intValue(cc);

            intValue >> n;
             ;
        }
        s.clear();
        int i = 0 ;
        while(n != 0){
            if(n%2 == 1){
                s.push_back(t[i]) ;
            }
            n/= 2 ;
            i++ ;
        }
        for(int i=s.size() -1 ; i>= 0; i--){
                if(begi){ cout <<s[i]  ;
                    begi = false ;
                }else{
                cout <<" " <<s[i]  ;
                }

        }
   }

}

int main(){
    solve();
}

