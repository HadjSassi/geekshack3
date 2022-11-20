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

	int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1};
	int dy[8] = { -1, 1, 0, 0, 1, -1, 1, -1};
	int sx = px;
	int sy = py;

	for (int i = 0; i < 8; ++i) {
		px = sx + dx[i];
		py = sy + dy[i];
		int d1 = abs(sx - gx);
		int d2 = abs(sy - gy);
		int D1 = abs(px - gx);
		int D2 = abs(py - gy);
		if (isValid(px, py) && (D1 <= d1 || D2 <= d2) ) {
			qx.push(px);
			qy.push(py);
			vis[px][py] = true;

		}
		if ()

		}

}
void BFS() {

	qx.push(Ppx);
	qy.push(Ppy);
	int x1, y1;
	vis[Ppx][Ppy] = true;

	while (!qy.empty()) {
		x1 = qx.front();
		y1 = qy.front();

		qx.pop();
		qy.pop();
		PossibleMoves( x1, y1);
		nb++;


	}
	cout << nb;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset (vis, false, sizeof(vis));




	cin >> NbObst;
	cin >> nbc >> nbl;
	cin >> gx >> gy >> Ppx >> Ppy;

	for (int i = 0; i < NbObst; ++i) {
		cin >> Pobs[i][0] >> Pobs[i][1];
	}

	BFS();


}