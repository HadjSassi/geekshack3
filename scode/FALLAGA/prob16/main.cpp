#include<bits/stdc++.h>
using namespace std;

pair<int,string> mat[9][9]; // 0 white , 1 black
int n1,n2;
int ans;
vector<pair<pair<int,int>,string>> att;
vector<pair<pair<int,int>,string>> def;

int nbrLastpiece = 4 ;
int lastScore = 0 ;
int findLast(int ans){
 return (ans % 2 == 0) ;
}
bool possible(int tx,int ty, int ix, int iy, string type){
    if(mat[tx][ty].first == mat[ix][iy].first) return false;
    // if(mat[tx][ty].first == mat[ix][iy].first) return false;
    // if(type == "rook"){
    //     return !(tx-ix) || !(ty-iy);
    // }
    // if(type == "bishop"){
    //     return abs(tx-ix) == abs(ty - iy);
    // }
    // if(type == "knight"){
    //     return abs(tx-ix) + abs(ty-iy) == 3 && tx != ix && ty != iy;
    // }
    // if(type == "queen"){
    //     return possible(tx,ty,ix,iy,"bishop") || possible(tx,ty,ix,iy,"rook");
    // }
    // if(type == "king"){
    //     return abs(tx-ix)  <= 1 && abs(ty-iy) <= 1;
    // }
    // if(type == "pawn"){
    //     if(mat[ix][iy].first == 1){
    //         return tx ==ix+1 && ty==iy-1 || tx == ix+1 && ty == iy+1 || ty == iy && tx == ix+1;
    //     }else{
    //         return tx == ix - 1 && ty == iy + 1 || tx == ix - 1 && ty == iy - 1 || tx == ix-1 && ty == iy;
    //     }
    // }
    if(type == "bishop"){
        for(int i = ix, j = iy; i>=1 && j >= 1; --i,--j){
            if(i == tx && j == ty) return true;
            if(mat[i][j].first != -1) break;
        }
        for(int i = ix, j = iy; i<=8 && j<= 8; j++,i++){
            if(i == tx && j == ty) return true;
            if(mat[i][j].first != -1) break;
        }
        for(int i = ix, j = iy; i>=1 && j<=8; i--,j++){
            if(i == tx && j == ty) return true;
            if(mat[i][j].first != -1) break;
        }
        for(int i=ix,j=iy;i<=8 && j>= 1; i++,j--){
            if(i == tx && j == ty) return true;
            if(mat[i][j].first != -1) break;
        }
        return false;
    }
    if(type == "rook"){
        for(int i = ix-1, j=iy; i>=1; i--){
            if(i == tx && iy == ty) return true;
            if(mat[i][iy].first != -1) break;
        }
        for(int i = ix+1; i<=8; ++i){
            if(i == tx && iy == ty) return true;
            if(mat[i][iy].first != -1) break;
        }
        for(int j = iy-1; j>=1; --j){
            if(j == ty && ix == tx) return true;
            if(mat[ix][j].first != -1) break;
        }
        for(int j = iy+1; j<9; ++j){
            if(j == ty && ix == tx) return true;
            if(mat[ix][j].first != -1) break;
        }
        return false;
    }

    if(type == "knight"){
        //return abs(tx-ix) + abs(ty-iy) == 3 && tx != ix && ty != iy;
        if(tx == ix-2 && (ty == iy-1 || ty == iy+1) || ty == iy+2 && (tx == ix-1 || tx == ix+1)
            || tx == ix + 2 && (ty == iy+1 || ty == iy-1) || ty == iy-2 && (tx == ix-1 || tx == ix + 1)) return 1;
        return false;
    }
    if(type == "queen") return possible(tx,ty,ix,iy,"bishop") || possible(tx,ty,ix,iy,"rook");
    if(type == "king"){
        for(int i = ix-1; i<=ix+1; ++i){
            for(int j = iy-1; j<=iy+1; ++j){
                if(i == tx && j == ty) return true;
            }
        }
        return false;
    }
    if(type == "pawn"){
        return tx == ix - 1 && ty == iy + 1 || tx == ix - 1 && ty == iy - 1 || tx == ix-1 && ty == iy;
    }
    return false;
}



bool canDefend(int ax, int ay,string typea, int kx, int ky){
    for(auto d : def){
        int dx = d.first.first, dy = d.first.second;

        string typed = d.second;
        pair<int,string> auxd1,auxd2;
        for(int i = 1; i<9; ++i){
            for(int j = 1; j<9; ++j){
                if(possible(i,j,dx,dy,typed)){

                    auxd1 = mat[dx][dy];
                    auxd2 = mat[i][j];
                    mat[i][j] = mat[dx][dy];
                    mat[dx][dy].first = -1;


                    if(dx == kx && dy == ky){
                        bool def = true;
                        for(auto at : att){
                            int xat = at.first.first, yat = at.first.second;
                            if(possible(i,j,xat,yat,typea)) {
                                def = false;
                                break;
                            }
                        }
                        if(def) return true;
                        continue;
                    }


                    if(possible(ax,ay,i,j,typed)){
                        return true;
                    }
                    if(!possible(kx,ky,ax,ay,typea)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void attack(int c,int kx,int ky){

    for(int i = 1; i<9; ++i){
        for(int j = 1; j<9; ++j){
            if(mat[i][j].first == c){
                att.push_back({{i,j},mat[i][j].second});
            }else if(mat[i][j].first == 1 - c){
                def.push_back({{i,j},mat[i][j].second});
            }
        }
    }



    for(auto a : att){
        int xa = a.first.first;
        int ya = a.first.second;
        string typea = a.second;
        pair<int,string> auxa1;
        pair<int,string> auxa2;
        for(int i = 1; i<9; ++i){
            for(int j = 1; j<9; ++j){

                if(possible(i,j,xa,ya,typea)){

                    auxa1 = mat[i][j];
                    auxa2 = mat[xa][ya];
                    mat[i][j] = mat[xa][ya];
                    mat[xa][ya].first = -1;
                    if(possible(kx,ky,i,j,typea)){
                        if(!canDefend(i,j,typea,kx,ky)){
                            ans++;
                        }
                    }
                    mat[i][j] = auxa1;
                    mat[xa][ya] = auxa2;
                }
            }
        }
    }
    ans = (ans % 2 == 0 && ans < 3) ? 3 : ans;

}

void solve(){
    int c1,c2;
    for(int i = 0; i<9; ++i){
        for(int j = 0; j<9; ++j){
            mat[i][j].first = -1;
            mat[i][j].second = "";
        }
    }
    n1 = 0,n2 = 0;
    ans = 0;
    cin >> c1 >> n1 >> c2 >> n2;
    int kx, ky, ck;
    cin >> ck >> kx >> ky;
    mat[kx][ky].second = "king";
    mat[kx][ky].first = ck;
    if(ck == c1) n1--;
    else n2--;
    for(int i = 0; i<n1; ++i){
        int c,x,y;
        string type;
        cin >> c >> x >> y >> type;
        mat[x][y].first = c;
        mat[x][y].second = type;
    }



    for(int i = 0; i<n2; ++i){
        int c,x,y;
        string type;
        cin >> c >> x >> y >> type;
        mat[x][y].first = c;
        mat[x][y].second = type;
    }


    if(ck == c1){
        //attack with second color
        attack(c2,kx,ky);
    }else{
        //attack with first color
        attack(c1,kx,ky);
    }

    if(ans > nbrLastpiece){
        cout << findLast(ans);
        return;
    } else{
        cout << (ans + 1) % nbrLastpiece;

    }
    if(ans < nbrLastpiece){
        if(n2!=1)
          cout << ans << '\n';
          else cout<<lastScore<<endl;
}}

int main(){
    solve();
}
