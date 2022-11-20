#include<bits/stdc++.h>
using namespace std;

string spO = string{'"','\'','(','{','[','`'};
map<char,char> closing;



void solve(){
    closing['('] = ')';
    closing['{'] = '}';
    closing['\''] = '\'';
    closing['"'] = '"';
    closing['['] = ']';
    string s;
    cin >> s;
    int n = s.length();
    
    
    vector<string> ans;
    string fixed = s;
    for(int i = 0; i<n; ++i){
        if(spO.find(s[i]) != string::npos){
            if(s.find(closing[s[i]],i+1) != string::npos){
                int end = s.find(closing[s[i]],i+1);
                if(s[i] == s[end]){
                    ans.push_back(fixed.substr(i,end-i+1));
                    s[i] = '0';
                    s[end] ='0';
                
                }else{
                    int cnt = 1;
                    end = i + 1;
                    while(end < n){
                        if(s[end] == s[i]) cnt++;
                        if(closing[s[i]] == s[end]) cnt--;
                    
                        if(!cnt) break;
                        end++;
                    }
                    if(!cnt){
                        ans.push_back(fixed.substr(i,end-i+1));
                        s[i] = s[end] = '0';
                    }
                }
                
            }
        }
    }
    if(ans.size()==0){
        cout<<"SYNTAX_ERROR";
        return;
    }
    for(int i = 0; i<ans.size(); ++i){
        cout << ans[i];
        if(i < ans.size() - 1) cout << ' ';
    }
}

int main(){
    solve();
}