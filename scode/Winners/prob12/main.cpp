#include <bits/stdc++.h>

using namespace std;
int Maze[1005][1005];
int nbCols,nbRows, PosGx,PosGy,PosPx,PosPy,nbObs;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,1,-1,-1,0,1};

bool verif( int x, int y){
	return ( x >= 0 && x < nbRows) && (y>=0 && y<nbCols);
}

struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis): x(x), y(y), dis(dis)
    {}
};

int BFSGhosttoP()
{
    queue<cell> q;
 
    q.push(cell(PosGx, PosGy, 0));

    cell t;
    int x, y;
    bool visit[nbCols][nbRows];
 
    for (int i = 0; i < nbCols; i++)
        for (int j = 0; j < nbRows; j++)
            visit[i][j] = false;
 
    visit[PosGx][PosGy] = true;
 
    while (!q.empty()) {
        t = q.front();
		//cout << t.x <<  " " << t.y << "debug" << endl;
        q.pop();
 
        if (t.x == PosPx && t.y == PosPy)
            return t.dis;
 
		for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (verif(x, y) && !visit[x][y] && Maze[x][y]!=-1) {
                visit[x][y] = true;
				//cout << x << " " << y << " debug" << endl;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
	return 0;
}

int main(){
	if (!(cin >> nbCols >> nbRows)){
		cout << "INPUT_ERROR" <<endl;
		return 0;
	}
	if (!(cin >> PosGx >> PosGy >> PosPx >> PosPy)){
		cout << "INPUT_ERROR" <<endl;
		return 0;
	}
	if (!(cin >> nbObs)){
		cout << "INPUT_ERROR" <<endl;
	}
	/*if (nbCols<0 || nbCols>9 || nbRows<0 || nbRows>9 || PosGx<0 || PosGx>0 || PosPx<0 || PosPy>9 || PosPy<0 || PosPy>9 || nbObs<0 || nbObs>9){
		cout << "INPUT_ERROR" <<endl;
		return 0;
	}*/
	//long long Maze[nbCol][nbRows];
	/*for (long long i=0;i<nbCol;i++){
		for (long long j=0;j<nbRows;j++){
			Maze[i][j] = 0;
		}
	}*/
	Maze[PosGx][PosGy] = -2;
	bool b = true;
	for (int i=0;i<nbObs;i++){
		int x,y;
		if (!(cin >> x >> y)){
			b=false;
		}
		/*if (x<0 || x>9 || y<0 || y>9){
			cout << "INPUT_ERROR" << endl;
			b=false;
		}*/
		//cout << x << " " << y << endl;
		Maze[x][y] = -1;
	}
	
	if (!b){
		cout <<"INPUT_ERROR" << endl;
		return 0;
	}
	cout << BFSGhosttoP() << endl;
	return 0;
}