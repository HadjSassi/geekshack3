#include <bits/stdc++.h>


using namespace std;

int main() {


	int t[4]={0,0,0,0};
	int p;
	cin >> t[0] >> t[1] >> t[2] >> t[3];
	if (t[3]==0) cout << "NO";
	else {
		sort(t, t + 4);
		p = min(t[0], t[1]) * min(t[2], t[3]);
		cout << p;
	}
	


}