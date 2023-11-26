#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 200000 + 10;

string types[] = {"S", "H", "C", "D"};
string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
int scores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10};

map<multiset<string>, bool> mp;

int ans = 0;

void work(multiset<string> s, int val, int it = 0){
  // for(string sss : s) cout<<sss<<' ';
  // cout<<endl<<val<<endl;
  if(s.empty()) ans = max(ans, val);
  if(mp.count(s)) return;
  for(int i=1; i<14; i++){
    string num = numbers[i];
    int sc = scores[i];
    string s1 = "H"+num;
    string s2 = "S"+num;
    string s3 = "C"+num;
    string s4 = "D"+num;
    bool b1 = s.count(s1), b2 = s.count(s2);
    bool b3 = s.count(s3), b4 = s.count(s4);
    if(b1 && b2 && b3 && b4){
      s.erase(s.find(s1));s.erase(s.find(s2));s.erase(s.find(s3));s.erase(s.find(s4));
      work(s, val + sc*4, it+1);
      s.insert(s1);s.insert(s2);s.insert(s3);s.insert(s4);
    }
    if(b1 && b2 && b3){
      s.erase(s.find(s1));s.erase(s.find(s2));s.erase(s.find(s3));
      work(s, val + sc*3, it+1);
      s.insert(s1);s.insert(s2);s.insert(s3);
    }
    if(b1 && b2 && b4){
      s.erase(s.find(s1));s.erase(s.find(s2));s.erase(s.find(s4));
      work(s, val + sc*3, it+1); 
      s.insert(s1);s.insert(s2);s.insert(s4);
    }
    if(b1 && b4 && b3){
      s.erase(s.find(s1));s.erase(s.find(s4));s.erase(s.find(s3));
      work(s, val + sc*3, it+1); 
      s.insert(s1);s.insert(s4);s.insert(s3);
    }
    if(b2 && b4 && b3){
      s.erase(s.find(s2));s.erase(s.find(s4));s.erase(s.find(s3));
      work(s, val + sc*3, it+1); 
      s.insert(s2);s.insert(s4);s.insert(s3);
    }
  }
  for(int tt = 0; tt < 4; tt++){
    string type = types[tt];
    for(int i=0; i<14; i++){
      for(int j=i+2; j<min(14, i+5); j++){
        bool bb = true;
        for(int k = i; k <= j; k++){
          string sss = type + numbers[k];
          if(!s.count(sss)){
            bb = false;
            break;
          }
        }
        if(bb){
          int sum = 0;
          for(int k = i; k<=j; k++){
            string sss = type + numbers[k];
            s.erase(s.find(sss));
            sum += scores[k];
          }
          work(s, val+sum, it+1); 
          for(int k = i; k<=j; k++){
            string sss = type + numbers[k];
            s.insert(sss);
          }
        }
      }
    }
  }
}

void solve(){
  multiset<string> s;
  for(int i=1; i<=14; i++){
    string t;
    cin>>t;
    s.insert(t);
  }
  work(s, 0);
  if(ans >= 72) cout<<"YES "<<ans;
  else cout<<"NO";
}

signed main(){
  // FAST;
  ll tt = 1;
//   freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  // cin >> tt;
  while (tt--) solve();
  return 0;
} 