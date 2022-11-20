#include <bits/stdc++.h>

using namespace std;
int Maze[1005][1005];
int MS[1005][1005];
int MT[1005][1005];
int nbCols,nbRows, PosGx,PosGy,PosPx,PosPy,nbObs;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int visitedT[1005][1005];
int visitedS[1005][1005];

int dpT[1005][1005];
int dpS[1005][1005];

bool verif( int x, int y,int nbRows, int nbCols){
	return ( x >= 0 && x < nbRows) && (y>=0 && y<nbCols);
}
bool verifS( int x, int y){
	return ( visitedS[x][y] == 0 && MS[x][y] == 1 );
}
bool verifT( int x, int y){
	return ( visitedT[x][y] == 0 && MT[x][y] == 1 );
}
struct cell {
    int x, y;
    int val;
    cell() {}
    cell(int x, int y, int val): x(x), y(y), val(val)
    {}
};


int calS(int x,int y){
	int newx,newy;
	if (visitedS[x][y] == 0 && MS[x][y] == 1) 
	{
		visitedS[x][y] = 1;
		
		for (int i=0;i<4;i++){
			newx= x + dx[i];
			newy= y+ dy[i];
			dpS[x][y] +=  calS(newx,newy);
		}
		dpS[x][y]++;
		return dpS[x][y] ;
	}
	return 0;
}
int calT(int x,int y){
	int newx,newy;
	if (visitedT[x][y] == 0 && MT[x][y] == 1) 
	{
		visitedT[x][y] = 1;
		
		for (int i=0;i<4;i++){
			newx= x + dx[i];
			newy= y+ dy[i];
			dpT[x][y] +=  calT(newx,newy);
		}
		dpT[x][y]++;
		return dpT[x][y] ;
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
	int m = 0;
	for(int i=0;i<inpstr.size();i++){
		m = max(m,(int)inpstr[i].size());
		for (int k=0;k<inpstr[i].size();k++){
			if (inpstr[i][k][0] == '0'){
				MS[i][k] = 0;
				MT[i][k] = 0;
			} else if (inpstr[i][k][0] == 'S'){
				MS[i][k] = 1;
				MT[i][k] = 0;
			} else if (inpstr[i][k][0] == 'T'){
				MS[i][k] = 0;
				MT[i][k] = 1;
			}
		}
	}
	nbCols = m;
	/*for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << MS[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << MT[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i=0;i<nbRows;i++){
		for (int j = 0;j<nbCols;j++){
			if (visitedS[i][j] == 0 && MS[i][j] == 1){
				MS[i][j] = calS(i,j);
			}
		}
	}
	for (int i=0;i<nbRows;i++){
		for (int j = 0;j<nbCols;j++){
			if (visitedT[i][j] == 0 && MT[i][j] == 1){
				MT[i][j] = calT(i,j);
			}
		}
	}
	vector<int> res;
	/*for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << MT[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			cout << dpT[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<int> ResS;
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			if ( ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1]) ){
				
				ResS.push_back(dpS[i][j]);
			} else
			if (  ( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1])&&!verif(i+1,j,nbRows,nbCols) ){
				ResS.push_back(dpS[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j]) &&  ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1])&&!verif(i,j+1,nbRows,nbCols) ){
				ResS.push_back(dpS[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1]) && ( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1]) &&!verif(i-1,j,nbRows,nbCols)){
				ResS.push_back(dpS[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j])&&!verif(i,j-1,nbRows,nbCols) ){
				ResS.push_back(dpS[i][j]);

			}else
			if (  ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j]) &&( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1]) &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				ResS.push_back(dpS[i][j]);

			}else
			if ( ( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1]) && ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				ResS.push_back(dpS[i][j]);
			}else
			if ( ( verif(i-1,j,nbRows,nbCols) && dpS[i][j]>dpS[i-1][j]) && ( verif(i,j-1,nbRows,nbCols) && dpS[i][j]>dpS[i][j-1])  &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				ResS.push_back(dpS[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpS[i][j]>dpS[i+1][j]) &&( verif(i,j+1,nbRows,nbCols) && dpS[i][j]>dpS[i][j+1])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				ResS.push_back(dpS[i][j]);
			}
		}
	}
	sort(ResS.begin(),ResS.end());
	cout << "S ";
	for (int i=0;i<ResS.size()-1;i++){
		cout << ResS[i] * 100 << " ";
	}
	cout << ResS[ResS.size()-1] * 100 << "\n";
	
	
	
	vector<int> ResT;
	for (int i=0;i<nbRows;i++){
		for (int j=0;j<nbCols;j++){
			if ( ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpT[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpT[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1]) ){
				
				ResT.push_back(dpT[i][j]);
			} else
			if (  ( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpT[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1])&&!verif(i+1,j,nbRows,nbCols) ){
				ResT.push_back(dpT[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpT[i+1][j]) &&  ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j]) &&( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1])&&!verif(i,j+1,nbRows,nbCols) ){
				ResT.push_back(dpT[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpT[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpT[i][j+1]) && ( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1]) &&!verif(i-1,j,nbRows,nbCols)){
				ResT.push_back(dpT[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpT[i+1][j]) && ( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpT[i][j+1]) && ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j])&&!verif(i,j-1,nbRows,nbCols) ){
				ResT.push_back(dpT[i][j]);

			}else
			if (  ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j]) &&( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpT[i][j+1]) &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				ResT.push_back(dpT[i][j]);

			}else
			if ( ( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1]) && ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpT[i+1][j])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				ResT.push_back(dpT[i][j]);
			}else
			if ( ( verif(i-1,j,nbRows,nbCols) && dpT[i][j]>dpT[i-1][j]) && ( verif(i,j-1,nbRows,nbCols) && dpT[i][j]>dpT[i][j-1])  &&!verif(i+1,j,nbRows,nbCols) && !verif(i,j+1,nbRows,nbCols) ){
				ResT.push_back(dpT[i][j]);
			}else
			if ( ( verif(i+1,j,nbRows,nbCols) && dpT[i][j]>dpS[i+1][j]) &&( verif(i,j+1,nbRows,nbCols) && dpT[i][j]>dpS[i][j+1])  &&!verif(i-1,j,nbRows,nbCols) && !verif(i,j-1,nbRows,nbCols)){
				ResT.push_back(dpT[i][j]);
			}
		}
	}
	sort(ResT.begin(),ResT.end());
	cout << "T ";
	for (int i=0;i<ResT.size()-1;i++){
		cout << ResT[i] * 100 << " ";
	}
	cout << ResT[ResT.size()-1] * 100 << "\n";
	return 0;
}