#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin,s);
    vector<int> v;
    bool error = false;
    for(int i = 0; i<s.length(); ++i){
        if(s[i] == ' ') continue;
        if(s[i] >= '0' && s[i] <= '9'){
            int nb = s[i] - '0';
            v.push_back(nb);
        }else{
            error = true;
        }
    }
    if(error || v.size() < 4){
        cout << "NO";
        return;
    }
    sort(v.begin(),v.end());
    cout << v[0]*v[2] << '\n';
}


int main(){
    solve();
}