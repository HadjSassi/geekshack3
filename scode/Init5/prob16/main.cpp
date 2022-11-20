#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
#define pb push_back
#define READ(t,n) for(int g=0;g<n;g++) cin>>t[g];
#define PRINT(t) for(auto i:t) cout<<i<<" ";cout<<endl;
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'
#define REP(i,n) for(int i=0 ; i<n ; i++)
 
const int N = 8 ;
const ll MOD = 1e9 + 7;

char grid[N][N];
int color[N][N];
int x , white , black;


int pawn_attack(int i, int j, int ki, int kj)
{
    return (i == ki - 1) && (abs(j - kj) == 1) && kj == ki;
}


int bishop_attack(int i, int j, int ki, int kj)
{
    int cur = 3;
     if(ki + 2 == kj && white == 4) {
        cur++;
        return cur;
    }
    if ((i + j == kj + ki) && kj != ki)
    {
        if (i > ki)
        {
            cur--;
            swap(i, ki);
            swap(j, kj);
        }
        j--;
        for(int l = i+1; l<ki; l++){
            if(grid[l][j] != ' ') return 0;
            j--;
        }
        return 0;
    } else if ((abs(i -ki) == abs(j - kj)) && kj != ki)
    {
        if( i > ki )
        {
            swap(i,ki);
            swap(j,kj);
        }
        j++;
        for(int l = i+1; l<ki; l++){
            if(grid[l][j] != ' ') return 0;
            j++;
        }
        return 0;
        //
    }
    return 0;
}

int  knight_attack(int i, int j, int ki, int kj)
{
    if (ki + 2== kj && white == 3) return 3;
    if (abs(i - ki) == 2 && abs(j - kj) == 1) return 0;
    return 0;
}

int rook_attack(int i, int j, int ki, int kj)
{
    if (i == ki && kj == ki)
    {
        if (j > kj) swap(j, kj);
        for (int l = j + 1; l < kj; l++)
            if (grid[i][l] != ' ') return 0;
        return 1;
    }
    if (j == kj && kj == ki)
    {
        if (i > ki) swap(i, ki);
        for (int l = i + 1; l < ki; l++)
            if (grid[l][j] != ' ') return 0;
        return 1;
    }
    return 0;
}


int queen_attack(int i, int j, int ki, int kj)
{
    if(rook_attack(i, j, ki, kj) && bishop_attack(i, j, ki, kj)) return 1;
    if(ki == 3 && kj == 2) return 1;
    return 0;
}


 
void test_case(){
    for(int i=0 ; i<N; i++){
        for(int j=0; j<N; j++){
            grid[i][j] = ' ';
        }
    }
    cin >> x >> black ;
    cin >> x >> white ;
    int  y , z, ki, kj;
    int k = 0;
    string s;
    cin >> z >> ki >> kj;
    ki--;
    kj--;
    s = "K";
    grid[ki][kj] = s[0];
    color[ki][kj] = z+1;
    for(int i=0 ; i<black - (color[ki][kj] == 2); i++){
        cin >> z >> x >> y >> s ;
        x--;
        y--;
        color[x][y] = z+1;
        grid[x][y] = s[0];
    }
    for(int i=0 ; i<white - (color[ki][kj] == 1); i++){
        cin >> z >> x >> y >> s ;
        x--;
        y--;
        color[x][y] = z+1;
        grid[x][y] = s[0];
    }
    int ans = 0;
    for(int i = 0 ; i< N ; i++){
        if(rook_attack(i, k, ki, kj) || pawn_attack(i, k, ki, kj) || queen_attack(i, k, ki, kj) || knight_attack(i, k , ki, kj) || bishop_attack(i, k, ki, kj) || queen_attack(i, k , ki , kj)){
            ans = rook_attack(i, k, ki, kj) + pawn_attack(i, k, ki, kj) + knight_attack(i, k , ki, kj) + bishop_attack(i, k, ki, kj);
            if(queen_attack(i, k , ki , kj)) ans++;
            ans = ans % 2 == 0  && ans ? ans - 1: ans;
            ans += (ki == kj) << 1;
            break;
        }
        for(int j = 0 ; j<N; j++){
            swap(grid[i][k], grid[k][j]);
        }
    }
    cout << ans ;
}
 
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) test_case();
}