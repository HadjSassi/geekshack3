#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef long long ll;
int grid[20][10];
int main() {
    int n;
    cin >> n;
    string aafa;
    getline(cin,aafa);
    int m;
    for(int i = 0;i<n;i++){
        string s;
        getline(cin,s);
        stringstream geek(s);
        m = (s.size()+1)/2;
        for(int j = 0;j<(s.size()+1)/2;j++){
        geek >> grid[i][j];

        }

    }
    int c = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m;j++){
            set<int> set0;
            set0.insert(grid[i][j]);
            set0.insert(grid[i+1][j]);
            set0.insert(grid[i][j+1]);
            set0.insert(grid[i+1][j+1]);
            if(set0.size() == 4){
                if(abs(grid[i][j] - grid[i+1][j]) == 2 || abs(grid[i][j] - grid[i][j+1]) == 2)continue;
                c++;
            }
        }
    }
    cout << c;
}
