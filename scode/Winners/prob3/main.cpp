#include <bits/stdc++.h>

using namespace std;
int Maze[1005][1005];
int nbCols,nbRows, PosGx,PosGy,PosPx,PosPy,nbObs;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int visited[1005][1005];
int dp[1005][1005];

bool verif( int x, int y,int nbRows, int nbCols){
	return ( x >= 0 && x < nbRows) && (y>=0 && y<nbCols);
}
bool verif2( int x, int y){
	return ( visited[x][y] == 0 && Maze[x][y] == 1 );
}
struct cell {
    int x, y;
    int val;
    cell() {}
    cell(int x, int y, int dis): x(x), y(y), val(val)
    {}
};

/*int BFSRails(int x, int y)
{
    queue<cell> q;
 
    q.push(cell(x, y, 1));

    cell t;
    int x, y;
 
    visit[x][y] = true;
 
    while (!q.empty()) {
        t = q.front();
		//cout << t.x <<  " " << t.y << "debug" << endl;
        q.pop();
 
        if (t.x == PosPx && t.y == PosPy)
            return t.dis;
 
		for (int i = 0; i < 2; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (verif(x, y) && !visit[x][y] && Maze[x][y]==1) {
                visit[x][y] = true;
				//cout << x << " " << y << " debug" << endl;
                q.push(cell(x, y, t.val + 1));
            } 
        }
		//if (( x+1<=NbRows-1 && Maze[x+1][y] == 0 && y+1 <=NbRows-1 && Maze[x][y+1] == 0) || (x+1<=NbRows-1 && Maze[x+1][y] == 0 && y == nbCols-1) || (y+1 <=NbRows-1 && Maze[x][y+1] == 0 && x == nbRows -1) )
    }
	return 0;
}*/

int cal(int x,int y){
	int newx,newy;
	if (visited[x][y] == 0 && Maze[x][y] == 1) 
	{
		visited[x][y] = 1;
		
		for (int i=0;i<4;i++){
			newx= x + dx[i];
			newy= y+ dy[i];
			dp[x][y] +=  cal(newx,newy);
		}
		dp[x][y]++;
		return dp[x][y] ;
	}
	return 0;
}

int main(){
	int nbRows,nbCols;
	if (!(cin >> nbRows)){
		cout << "NO" << endl;
	}
	cin.ignore();
	vector<vector<int>> input(nbRows);
	vector<vector<string>> inpstr(nbRows);
	vector<string> inputst;
	for (int i=0;i<nbRows;i++){
		string str;
		getline(cin,str);
		inputst.push_back(str);
	}
	for (int j=0;j<nbRows;j++){
		int PrevInd = 0;
		for(int i=0;i<inputst[j].size();i++){
			if ( inputst[j][i]== ' ' ){
				inpstr[j].push_back( inputst[j].substr(PrevInd,i-PrevInd) );
				PrevInd = i+1;
			}
			if (i == inputst[j].size() - 1 ){
				inpstr[j].push_back(inputst[j].substr(PrevInd,i-PrevInd+1));
			}
		}
		//cout << inputst[j] << endl;

	}
	bool b =true;
	for(int i=0;i<inpstr.size();i++){
		for (int k=0;k<inpstr[i].size();k++){
			//cout << inpstr[i][k] << " ";
			bool b2 = true;
			for (int j=0;j<inpstr[i][k].size();j++){
				
				if (!isdigit(inpstr[i][k][j])){
					b2 = false;
					b=false;
				}
			}
			if (b2){
				input[i].push_back(stoi(inpstr[i][k]));
			}
		}
	}
	if (!b){
		cout << "NO" << endl;
		return 0;
	}

	int m=0;
	for(int i=0;i<nbRows;i++){
		for (int j=0;j<input[i].size();j++){
			m = max(m,input[i][j]);
		}
	}
	nbCols = m + 1;
	//int mat[nbRows][nbCols];
	for (int i=0;i<input.size();i++){
		for (int j=0;j<input[i].size();j++){
			Maze[i][input[i][j]] = 1; 
		}
	}

	for (int i=0;i<nbRows;i++){
		for (int j = 0;j<nbCols;j++){
			if (visited[i][j] == 0 && Maze[i][j] == 1){
				Maze[i][j] = cal(i,j);
			}
		}
	}
	vector<int> res;
	/*for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << Maze[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<int> Res;
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			/*cout << i << " " << j << endl;
			bool b1 = verif(i+1,j,nbRows,nbCols);
			bool b2 = dp[i][j]>dp[i+1][j];
			bool b3= verif(i,j+1,nbRows,nbCols);
			bool b4 = dp[i][j]>dp[i][j+1];
			cout << b1 <<b2 << b3 << b4 <<endl;
			bool b = verif(i+1,j) && (dp[i][j]>dp[i+1][j]) &&  verif(i,j+1) && (dp[i][j]>dp[i][j+1]) &&  verif(i,j-1) && (dp[i][j]>dp[i][j-1]);
			cout << b <<"ayy" << endl;*/
			if ( ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1]) ){
				
				Res.push_back(dp[i][j]);
			} else
			if (  ( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1])&&!verif(i+1,j,nbRows,nbCols) ){
				
				Res.push_back(dp[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j]) &&  ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1])&&!verif(i,j+1,nbRows,nbCols) ){
				Res.push_back(dp[i][j]);
				

			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1]) && ( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1]) &&!verif(i-1,j,nbRows,nbCols)){
				Res.push_back(dp[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j])&&!verif(i,j-1,nbRows,nbCols) ){
				Res.push_back(dp[i][j]);

			}else
			if (  ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j]) &&( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1]) &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				Res.push_back(dp[i][j]);

			}else
			if ( ( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1]) && ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				Res.push_back(dp[i][j]);
				

			}else
			if ( ( verif(i-1,j,nbRows,nbCols) && dp[i][j]>dp[i-1][j]) && ( verif(i,j-1,nbRows,nbCols) && dp[i][j]>dp[i][j-1])  &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				Res.push_back(dp[i][j]);
				

			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dp[i][j]>dp[i+1][j]) &&( verif(i,j+1,nbRows,nbCols) && dp[i][j]>dp[i][j+1])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				Res.push_back(dp[i][j]);
				

			}
		}
	}
	sort(Res.begin(),Res.end());
	for (int i=0;i<Res.size();i++){
		cout << Res[i] * 100 << "\n";
	}
	return 0;
}