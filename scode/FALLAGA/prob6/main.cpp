
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
vector<int>d ;
vector<int>p ;
vector<char>cha ;

int ma = 0  ;
string res = "" ;
int h , n;
void recc(int pos , int &score,int hours, string &rep){
    if(pos>=n)return ;
    string rep1 = rep, rep2 =rep ;
    int score1 = score, score2= score ;
    recc(pos + 1 , score1 , hours, rep1) ;
    if(d[pos]<=hours){
        recc(pos+1 , score2 , hours-d[pos], rep2) ;
        rep2 = ' '+ rep2 ;
        rep2 = cha[pos]+rep2 ;
        if(score1 > score2+p[pos]){
            score = score1 ;
            rep = rep1 ;
        }else{
            score = score2+p[pos] ;
            rep = rep2 ;
        }
    }else{
        score = score1 ;
        rep = rep1 ;

    }
}

void solve(){

    cin >> h >> n ;
    int duration , profit ;
    char c ;

    for(int i=0 ;i<n ;i++){
        cin >> c>> duration >> profit ;
        d.push_back(duration) ;
        p.push_back(profit) ;
        cha.push_back(c) ;
    }
    int finalScore = 0 ;
    recc(0,finalScore,h,res) ;
    res.pop_back();
    cout <<  res<< endl ;
    cout << finalScore  ;
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

