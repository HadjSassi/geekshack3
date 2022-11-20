#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = (x); i <= (y); i++)
#define forr(i, x, y) for (int i = (x); i < (y); i++)
#define forrl(i, x, y) for (ll i = (x); i < (y); i++)
#define dow(i, x, y) for (int i = (x); i >= (y); i--)

#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
const int N = 1e4;

struct point
{
    int x;
    int y;
};

int poss_R[8][2];
int  board[8][8];
bool covered[8][8];
void solve()
{
    int att_k[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    ll n, nb_black, nb_white, k, m, x, y,ans;
    string s;
    int black, white;
    point king_b;
    cin >> nb_black >> nb_black;
    cin >> nb_white >> nb_white;
    cin >> black >> king_b.x >> king_b.y;
    king_b.x--;
    king_b.y--;
    board[king_b.x][king_b.y]=1;
    if (black == 0)
    {
        swap(nb_black, nb_white);
        black = 1;
        white = 0;
    }
    vector<point> bl[5];
    vector<point> wh[5];
    for (int i = 0; i < nb_black + nb_white-1; i++)
    {
        int col;
        point curr;
        string s;
        cin >> col >> curr.x >> curr.y >> s;
        curr.x--;
        curr.y--;
        board[curr.x][curr.y]=1;
        if (col == black)
        {
            if (s[0] == 'r')
            {
                bl[0].push_back(curr);
            }
            else if (s[0] == 'k')
            {
                bl[1].push_back(curr);
            }
            else if (s[0] == 'b')
            {
                bl[2].push_back(curr);
            }
            else if (s[0] == 'q')
            {
                bl[3].push_back(curr);
            }
            else if (s[0] == 'p')
            {
                bl[4].push_back(curr);
            }
        }
        else
        {
            if (s[0] == 'r')
            {
                wh[0].push_back(curr);
            }
            else if (s[0] == 'k')
            {
                wh[1].push_back(curr);
            }
            else if (s[0] == 'b')
            {
                wh[2].push_back(curr);
            }
            else if (s[0] == 'q')
            {
                wh[3].push_back(curr);
            }
            else if (s[0] == 'p')
            {
                wh[4].push_back(curr);
            }
        }
    }
ans +=max(bl[0].size(),wh[0].size())/2+2*wh[3].size()-wh[4].size()-wh[1].size()/2-min(bl[0].size(),wh[0].size())/2+bl[3].size()*bl[1].size()*3+(nb_black == 1 ? 2 : 0);
    for(int i = 0 ; i<5 ; i++){
        for(int j = 0 ; j<bl[i].size();j++){
            int xx=bl[i][j].x,yy=bl[i][j].y;
            if(i==0){
                for(int k=xx+1 ; k<8;k++){
                    if(board[k][yy]==1){
                        break;
                    }
                    board[k][yy]=2;
                }
                  for(int k=xx-1 ; k>=0;k--){
                    if(board[k][yy]==1){
                        break;
                    }
                    board[k][yy]=2;
                }
                  for(int k=yy+1 ; k<8;k++){
                    if(board[xx][k]==1){
                        break;
                    }
                    board[xx][k]=2;
                }
                for(int k=yy-1 ; k>=0;k--){
                    if(board[xx][k]==1){
                        break;
                    }
                    board[xx][k]=2;
                }
            } 
            else if(i==1){
                for(int k = 0 ; k<8;k++){
                    int aa=att_k[k][0],bb=att_k[k][1];
                    if(xx+aa>7||xx+aa<0||yy+bb>7||yy+bb<0){continue;}
                    else if(board[xx+aa][yy+bb]==0){
                        board[xx+aa][yy+bb]=2;
                    }
                }
            }
            else if (i==2){
                 for(int k=1 ; xx+k<8&&yy+k<8;k++){
                    if(board[xx+k][yy+k]==1){
                        break;
                    }
                    else{
                        board[xx+k][yy+k]=2;
                    }
                    
                }
                  for(int k=-1 ; xx+k>=0&&yy+k>=0;k--){
                     if(board[xx+k][yy+k]==1){
                        break;
                    } else{
                        board[xx+k][yy+k]=2;
                    }
                }
                       for(int k=1 ; xx+k<8&&yy-k>=0;k++){
                    if(board[xx+k][yy-k]==1){
                        break;
                    }
                     else{
                        board[xx+k][yy-k]=2;
                    }
                }
                  for(int k=1 ; xx-k>=0&&yy+k<8;k++){
                     if(board[xx-k][yy+k]==1){
                        break;
                    } else{
                        board[xx-k][yy+k]=2;
                    }
                }
            }
            else if (i==4){
               if( board[xx+1][max(0,yy-1)]==0){
                   board[xx+1][max(0,yy-1)]=2;
               }
               if( board[xx+1][yy]==0){
                   board[xx+1][yy]=2;
               }
               if( board[xx+1][min(7,yy+1)]==0){
                   board[xx+1][min(7,yy+1)]=2;
               }
            }
        }
    }
    
    cout<<ans<<endl;
  

    return;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //init();
    // cin>>t;
    for (ll i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}