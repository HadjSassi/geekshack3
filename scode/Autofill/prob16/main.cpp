#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
typedef vector<pair<int,int>> vii;

int knightdirs[8][2]{{2,1}, {1,2},{-1, -2} , {-2 , -1} , {-1 , 2},{2, -1} , {-2 , 1} ,{1 , -2}};
int bishopdirs[4][2]{{-1,-1} , {1 , 1} , {-1,1} , {1,-1}};
int rook[4][2]{{1,0} , {0, 1} , {-1,  0} , {0 , -1}};
string grid[8][8];
char ma[2]{'1','0'};
void printgrid(){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(grid[i][j] == "")cout << '.';
            else cout << grid[i][j][0];

        }
        cout << endl;
    }
}
vector<pair<int,int>> generatemoves(int x , int y){
    vector<pair<int,int>> moves;
    if(grid[x][y] == "knight1" || grid[x][y] == "knight0"){
        int c = (int)(grid[x][y].back() - '0');
        for(auto p : knightdirs){
            int x0 = x + p[0];
            int y0 = y + p[1];
            if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
            if(grid[x0][y0] == "" || grid[x0][y0].back() == ma[c]){
                moves.emplace_back(x0,y0);
            }
        }
    }else if(grid[x][y] == "bishop1" || grid[x][y] == "bishop0"){
        int c = (int)(grid[x][y].back() - '0');
        for(auto p : bishopdirs){
            for(int i = 1;i<=8;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == ""){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }
    }else if(grid[x][y] == "queen1" || grid[x][y] == "queen0"){
        int c = (int)(grid[x][y].back() - '0');
        for(auto p : bishopdirs){
            for(int i = 1;i<=8;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == ""){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }
        for(auto p : rook){
            for(int i = 1;i<=8;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == ""){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }

    }else if(grid[x][y] == "rook1" || grid[x][y] == "rook0"){
        int c = (int)(grid[x][y].back() - '0');
        for(auto p : rook){
            for(int i = 1;i<=8;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == "" && grid[x0][y0] != "\n"){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }
    }else if(grid[x][y] == "king1" || grid[x][y] == "king0"){
        int c = (int)(grid[x][y].back() - '0');
        for(auto p : bishopdirs){
            for(int i = 1;i<=1;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == ""){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }
        for(auto p : rook){
            for(int i = 1;i<=1;i++){

                int x0 = x + i * p[0];
                int y0 = y + i * p[1];
                if(x0 < 0  || y0 < 0 || x0 > 7 || y0 > 7)continue;
                if(grid[x0][y0] == ""){
                    moves.emplace_back(x0,y0);
                }
                else if(grid[x0][y0].back() == ma[c]){
                    moves.emplace_back(x0,y0);
                    break;
                }else break;
            }
        }
    };
    return moves;
}
char black = '1';
bool check(string board[8][8]){
    for(int i = 0;i<8;i++) {
        for (int j = 0; j < 8; j++) {
            if(grid[i][j] != "" && grid[i][j].back() == ma[black - '0']) {
                auto moves = generatemoves(i, j);
                for (auto p : moves) {
                    if (grid[p.first][p.second] == "king1" || grid[p.first][p.second] == "king0" )return 1;
                }
            }
        }
    }
    return 0;
}

bool check_mate(string board[8][8]){
    if(!check(board))return 0;
    for(int i = 0;i<8;i++) {
        for (int j = 0; j < 8; j++) {
            if(grid[i][j] != "" && grid[i][j].back() == black) {
                auto moves = generatemoves(i, j);

                for (auto p : moves) {
                    int x0 = p.first;
                    int y0 = p.second;


                    string temp = grid[x0][y0];
                    grid[x0][y0] = grid[i][j];
                    grid[i][j] = "";
                    // printgrid();
                    if(!check(grid)) {
                        grid[i][j] = grid[x0][y0];
                        grid[x0][y0] = temp;
                        return 0;
                    }
                    grid[i][j] = grid[x0][y0];
                    grid[x0][y0] = temp;


                }
            }
        }
    }
    return 1;
}

int main() {
    int c1,n,c2,m;
    cin >> c1 >> n >> c2 >> m;

    for(int i = 0;i<(n+m);i++){
        int c,x,y;
        cin >> c >> x >> y;
        x--;y--;
        string s;
        if(i == 0){
            s = "king";
            if(c == 0)black = '0';
        }else cin >> s;
        grid[x][y] = s + to_string(c);
    }
    int res = 0;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(grid[i][j] != "" && grid[i][j].back() == ma[black - '0']){
                auto moves = generatemoves(i,j);
                for(auto p : moves){
                    int x0 = p.first;
                    int y0 = p.second;


                    // cout << grid[i][j] << " " << x0+1 << " " << y0+1 << endl;
                    string temp = grid[x0][y0];
                    grid[x0][y0] = grid[i][j];
                    grid[i][j] = "";

                    if(check_mate(grid)){
                        // cout << i << " " << j << " " << x0 << " " << y0 << "Y" << endl;
                        res++;
                    }
                    grid[i][j] = grid[x0][y0];
                    grid[x0][y0] = temp;

                }
            }
        }
    }
    cout << res << endl;

}/*

1 2
0 1
1 1 3
0 3 2 queen
0 3 4 queen*/      