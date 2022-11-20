#include <bits/stdc++.h>
using namespace std;

set<char> exp0;
set<char> exp1;
map<char,char> ma;
map<char,char> mar;
bool valid(string s){
    if(s.length() <= 1)return 0;
    stack<char> st;
    if(ma[s[0]] != s.back())return 0;
    for(int i = 1;i<((int)s.length())-1;i++){
        char c = s[i];
        if(s[0] == c){
            st.push(c);
        }else
        if(s[i] == ma[s[0]]){
            if(st.empty())return 0;
            if(st.top() == mar[c]){
                st.pop();
            }
            else return 0;
        }
    }

    return st.empty();
}
int main()
{

    map<char,set<int>> poss;
    ma['('] = ')';
    ma['{'] = '}';
    ma['\''] = '\'';
    ma['\"'] = '\"';
    ma['`'] = '`';
    ma['['] = ']';

    mar[')'] = '(';
    mar['}'] = '{';
    mar['\''] = '\'';
    mar['\"'] = '\"';
    mar['`'] = '`';
    mar[']'] = '[';

    exp0.insert('(');
    exp0.insert('[');
    exp0.insert('{');

    exp1.insert(')');
    exp1.insert(']');
    exp1.insert('}');

    string s;
    getline(cin,s);

    int n = s.size();
    vector<bool> v(n,0);
    int c = 0;
    for(int i = 0;i<n;i++){
        if(v[i])continue;
        for(int j = 1;j<=(n-i);j++){
            string t = s.substr(i,j);
            if(valid(t)){
                v[i + j-1] = 1;
                if(c)cout << " ";
                c++;

                cout << t;
            }
        }
    }
    if(c == 0){
        cout << "SYNTAX_ERROR";
    }
    return 0;
}