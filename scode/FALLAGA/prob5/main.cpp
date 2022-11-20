#include<bits/stdc++.h>
using namespace std;


bool sim(string aux, string a){
    for(int i = 0; i<a.length(); ++i){
        if(a[i] == ' ') continue;
        if(aux.find(a[i]) != string::npos) return true;
    }
    return false;
}


vector<string> mod;
vector<string> notMod;
vector<string> uploaded;

void mergeBr(vector<string>& main,vector<string>a,vector<int>& kol){


    for(int i = 0; i<a.size(); ++i){
        bool eq = false;
        bool simi = false;
        string str = a[i];
        for(int j = 0; j<main.size(); ++j){
            if(str == main[j]){
                notMod.push_back(str);

                eq = true;
                kol[j]=1;
                //cout<<str<<" "<<main[j]<<" "<<j<<endl;
                break;
            }else{
                if(sim(main[j],str)){
                    main[j] = str;
                    mod.push_back(str);

                    simi = true;
                    kol[j]=1;
                    //cout<<str<<" "<<main[j]<<" "<<j<<endl;
                    break;
                }
            }
        }
        if(!eq && !simi){
            uploaded.push_back(str);
        }
    }
}

void solve(){
    int n;
    while(cin >> n){
	
    map<string,vector<string> > m;
    while(n--){
        string b,br;
        cin >> b >> br;
        string data;
        getline(cin,data);
        string l;
        for(int i = 0; i<data.length(); ++i){
            if(data[i] == ' ') continue;
            l.push_back(data[i]);
        }
        m[br].push_back(l);
    }

    vector<string> main = m["Main"];
    vector<string> a = m["A"];
    vector<string> b = m["B"];
    vector<int>kol(main.size(),0);
    mergeBr(main,a,kol);
    mergeBr(main,b,kol);
    for(int i =0;i<main.size();i++){
    	if(kol[i]==0){
    		notMod.push_back(main[i]);
		}
	}
    for(int i = 0; i<mod.size(); ++i){
        for(int j = 0; j<mod[i].length(); ++j){
            cout << mod[i][j] << ' ';
        }
        cout << ": M\n";
    }
    for(int i = 0; i<uploaded.size(); ++i){
        for(int j = 0; j<uploaded[i].length(); ++j){
            cout << uploaded[i][j] << ' ';
        }
        cout << ": U\n";
    }
    for(int i = 0; i<notMod.size(); ++i){
        for(int j = 0; j<notMod[i].length(); ++j){
            cout << notMod[i][j];
            if(j < notMod[i].length() - 1)
            cout << ' ';
            else{
                cout << '\n';
            }
        }
    }


    
return ;}
cout<<"NO";
}



int main(){

    solve();
}