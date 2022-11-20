#include<bits/stdc++.h>
using namespace std;

int t[100][100] ;

int cout_char(string s,char cc) {
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == cc) count++;

  return count;
}
bool test(int a, int b, int c , int d){
    string s = "" ;
    s+= to_string(a) ;
    s+= to_string(b) ;
    s+= to_string(c) ;
    s+= to_string(d) ;
    /*if((cout_char(s,'1') == 1) && (cout_char(s,'2') == 1) && (cout_char(s,'3') == 1) && (cout_char(s,'4') == 1) ){
        return true ;
    }*/
    //cout << s << ' ';
    if(s== "1234" || s == "2341" || s == "3412" || s == "4123" || s == "4321" || s == "3214" || s == "2143" || s == "1432"){
            return true ;
            }
    else{

    return false ;
    }
    //if(s == "1234" || s == "1243" || s == "1324" || s == "1342" || s == "1423" || s == "1432" || s == "2134" || s == "2143" || s == "2314" || s == "1234")
}

void solve(){
    int n ,k;
    cin >> n ;
    int j ;
    string s ;
    for(int i=0 ; i<n +1 ; i++){
        //cin.ignore() ;
        int jj =-1 ;
        getline(cin,s) ;

        stringstream intValue(s);
         while(intValue >> k){
                jj++ ;
                j = jj ;
           //cout << k <<"    ";
            t[i][j] = k ;
        }
        //cin.ignore() ;

    }

    //cout << j <<endl ;
    int ss =0 ;
    for(int i=1 ; i<n  ; i++){
        for(int z=0 ; z<j+1 ; z++){
              //  cout << t[i][z] << ' ' ;
            if(test(t[i][z] ,t[i][z+1] ,t[i+1][z+1] ,t[i+1][z] )) ss++ ;
        }
    }
    cout << ss ;

}

int main(){
    solve();
}


