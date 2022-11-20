#include <bits/stdc++.h>


using namespace std;
#define N 10000


int gx, gy;
int nbc, nbl;
int NbObst;
int nb = 0;
int Ppx, Ppy;
bool vis[N][N];

queue<int> qx;
queue<int> qy;
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = { -1, 1, 0, 0, 1, -1, 1, -1};

int Pobs[N][2];


bool isValid(int x, int y) {
	if (x > nbc || x < 0 || y < 0 || y > nbl) return false;
	for (int i = 0; i < NbObst; i++) {
		if (x == Pobs[i][0] && y == Pobs[i][1]) {
			return false;
		}  true;
	}
	return true;
}

void PossibleMoves(int px, int py) {

	int sx = px;
	int sy = py;

	for (int i = 0; i < 8; ++i) {
		px = sx + dx[i];
		py = sy + dy[i];
		int d1 = abs(sx - gx);
		int d2 = abs(sy - gy);
		int D1 = abs(px - gx);
		int D2 = abs(py - gy);
		if (isValid(px, py) && D1 <= d1 && D2 <= d2 && qy.size() < 1) {
			qx.push(px);
			qy.push(py);
			//cout << "possible move =" << px << " " << py << endl;
			vis[px][py] = true;

		}
	}
}
void BFS() {

	qx.push(Ppx);
	qy.push(Ppy);
	int x1, y1;
	vis[Ppx][Ppy] = true;

	while (true ) {
		x1 = qx.front();
		y1 = qy.front();
		//cout << "position in " << x1 << " " << y1 << endl;
		qx.pop();
		qy.pop();
		PossibleMoves( x1, y1);
		nb++;
		if (x1 == gx && y1 == gy) {cout<<nb-2;break;}
		if (qx.empty()) {cout<<"0"; break;}

	}


}

int main() {


	memset (vis, false, sizeof(vis));


	cin >> nbl >> nbc;
	cin >> gx >> gy >> Ppx >> Ppy;
	cin >> NbObst;

	for (int i = 0; i < NbObst; ++i) {
		cin >> Pobs[i][0] >> Pobs[i][1];
	}


	/*int x[8];
	int y[8];
	int xx = gx;
	int yy = gy;
	int a = 0;
	for (int i = 0; i < 8; ++i) {
		xx = gx + dx[i];
		yy = gy + dy[i];
		if (isValid(xx, yy)) {
			x[i] = xx;
			y[i] = yy;
			a++;
		}
	}
	bool stack = true;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < NbObst; ++j) {
			if (x[i] != Pobs[i][0] && y[i] != Pobs[i][1]) stack = false;
		}

	}

	if (stack) cout << "0";
	else */
	BFS();



} 