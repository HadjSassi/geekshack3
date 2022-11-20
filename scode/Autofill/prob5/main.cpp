#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;
set<string> words;
set<string> copy0;
vector<vector<string>> output[3];
int main() {
    int n;
    string t;
    getline(cin , t);
    if(t.size() == 0){
        cout << "NO" << endl;
        return 0;
    }

    stringstream test(t);
    test >>n;

    string s;
    while(n--){

        getline(cin,s);

        if(s[3] == 'M'){
            int i = 8;
            string temp = "";
            while(i < s.length()){

                char c = s[i];
                if(c == ' '){

                    words.insert(temp);
                    copy0.insert(temp);
                    temp = "";
                }
                else temp += s[i];
                i++;
            }
            words.insert(temp);
            copy0.insert(temp);
        }else {

            int i = 5;
            vs a;
            string temp;
            while(i < s.length()){
                char c = s[i];
                if(c == ' '){

                    a.pb(temp);
                    temp = "";
                }
                else temp += s[i];
                i++;
            }
            if(temp != "") a.pb(temp);
            int co = 0;
            for(string s1 : a){
                if(words.count(s1)){
                    co++;
                    copy0.erase(s1);
                }

            }
            if(co == 0){
                output[1].pb(a);
            }else if(co == a.size()){
                output[2].pb(a);
            }else output[0].pb(a);
        }
    }
    for(vs w  : output[0]){
        if(w.empty())continue;
        for(string s : w){
            cout << s << " ";
        }
        cout << ": M\n";
    }
    for(vs w  : output[1]){
        if(w.empty())continue;
        for(string s : w){
            cout << s << " ";
        }
        cout << ": U\n";
    }
    if(copy0.size()){
        vs temp;
        for(string s7: copy0)temp.pb(s7);
        int pm = temp.size();
        for(int i = 0;i<pm;i++){
            cout << temp[i];
            if(i != pm - 1)cout << " ";
        }
        cout << endl;
    }
    for(vs w  : output[2]){
        if(w.empty())continue;
        for(int i = 0;i<w.size();i++){
            cout << w[i] ;
            if(i != (w.size() - 1))cout << " ";
        }
        cout << endl;
    }
}