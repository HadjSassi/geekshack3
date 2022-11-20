#include <bits/stdc++.h>

using namespace std;

char v[10][10];
short dirs[4][2] {{-1, 0} , {0 , -1} , {1, 0},{0,1}};
vector<int> a;
int dfs(int x,int y){
    if(x < 0 || y < 0 || v[x][y] != 'S')return 0;
    v[x][y] = '0';
    int sum = 1;
    for(auto p : dirs){
        sum += dfs(x + p[0] , y + p[1]);
    }
    return sum;
}

int dfs1(int x,int y){
    if(x < 0 || y < 0 || v[x][y] != 'T')return 0;
    v[x][y] = '0';
    int sum = 1;
    for(auto p : dirs){
        sum += dfs1(x + p[0] , y + p[1]);
    }
    return sum;
}

int main() {
    int n;

    memset(v,'0',sizeof v);
    string s;
    getline(cin,s);
    if(s == ""){
        cout << "NO";
        return 0;
    }
    stringstream geek(s);
    geek >> n;
    for(int i = 0;i<n;i++){
        getline(cin,s);

        stringstream geek(s);
        int m = (s.size() + 1)/2;
        for(int j = 0;j<m;j++){
            geek >> v[i][j];
        }


    }
    for(int i = 0;i<n;i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j] != 'S')continue;
            a.push_back(dfs(i, j));
        }
    }
    sort(a.begin(),a.end());
    cout << "S ";
    for(int i = 0;i<a.size();i++){
        cout << a[i] * 100;
        if(i != a.size() - 1)cout << " ";
    }
    a.clear();
    for(int i = 0;i<n;i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j]!= 'T')continue;
            a.push_back(dfs1(i, j));
        }
    }
    cout << endl << "T ";
    sort(a.begin(),a.end());
    for(int i = 0;i<a.size();i++){
        cout << a[i] * 100;
        if(i != a.size() - 1)cout << " ";
    }
}
