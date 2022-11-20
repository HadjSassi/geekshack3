#include<bits/stdc++.h>
using namespace std;

int l,w;
int tsize,tnum;
int ans;

void solve(){
    cin >> l >> w;
    cin >> tsize;
    cin.ignore();
    char c;
    cin >> c;
    if(c >= '0' && c <= '9'){
        tnum = c - '0';
    }else{
        cout << "INPUT_ERROR";
        return;
    }
    if(l >= (tsize+1)*tnum + 1 || w >= (tsize+1)*tnum+1 ){
        cout << tnum*4;
    }else{
        int q;
        bool found = false;
        for(int i = tnum; i>=0; --i){
            if(l >= (tsize+1)*i + 1 || w >= (tsize+1)*i+1){
                found = true;
                q = tnum/i;
                break;
            }
        }
        if(found){
            int x = q*6;
            if(q%2){
                x += 4;
            }
            cout << x << '\n';
        }
            
    }
}

int main(){
    solve();
}