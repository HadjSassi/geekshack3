#include <bits/stdc++.h>


using namespace std;

int main() {


	int n, d;
	cin >> n >> d;


	int t[n];
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	int res = 0, j = 0;
	for (int i = 0; i < n; i++) {
		while (j <= d) {
			res++;
			if (j == t[i]) j = 0;
			j++;
		}
	}
	cout << res;
}