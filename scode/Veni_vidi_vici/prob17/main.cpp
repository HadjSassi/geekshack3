#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    set<string> words;
    words.insert(s);
    long long c = 1;
    int n = s.length();
    while(n-- > 1){
        set<string> list;
        for(string a : words){
            if(a.size() == 1)break;
            for(int i = 0;i<a.length()-1;i++){
                string x;
                if(a.substr(i,2) == "tt"){
                    x = a.substr(0,i) + "v";
                    if(i+2 < a.length())x += a.substr(i+2);
                }
                if(a.substr(i,2) == "vv"){
                    x = a.substr(0,i) + "t";
                    if(i+2 < a.length())x += a.substr(i+2);
                }
                if(x.size())list.insert(x);
            }
        }
        c+= list.size();
        words = list;
    }
    cout << c << endl;
}

   