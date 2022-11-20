#include <bits/stdc++.h>

using namespace std;

bool v[10][10];
short dirs[4][2] {{-1, 0} , {0 , -1} , {1, 0},{0,1}};
vector<int> a;
int dfs(int x,int y){
    if(x < 0 || y < 0 || v[x][y])return 0;
    v[x][y] = 1;
    int sum = 1;
    for(auto p : dirs){
        sum += dfs(x + p[0] , y + p[1]);
    }
    return sum;
}
int main() {
    int n;

    memset(v,1,sizeof v);
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

        int t = 0;
        for(int j = 0;j<s.length();j++){
            if(s[j] == ' ' ){
                v[i][t] = 0;

                t = 0;
            }
            else {
                t *=10;
                t += (int)(s[j] - '0');
            }
        }
        v[i][t] = 0;

        //cerr << endl;

    }
    for(int i = 0;i<n;i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j])continue;
            a.push_back(dfs(i, j));
        }
    }
    sort(a.begin(),a.end());
    for(int i = 0;i<a.size();i++){
        cout << a[i] * 100;
        if(i != a.size() - 1)cout << '\n';
    }

}
 