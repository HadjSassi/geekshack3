#include <bits/stdc++.h>


using namespace std;


typedef long int ll;

int main() {


	ll N, F, T, A;

	cin >> N >> F >> T >> A;

	ll AllerDiPr[N][2];
	ll RetourDiPr[N][2];

	for (ll i = 0; i < N; ++i) {
		cin >> AllerDiPr[i][0] >> AllerDiPr[i][1] >> RetourDiPr[i][0] >> RetourDiPr[i][1];
	}

	ll AllerNbtiPr[A][2];
	ll RetourNbtiPr[A][2];

	for (ll j = 0; j < A; ++j) {
		cin >> AllerNbtiPr[j][0] >> AllerNbtiPr[j][1] >> RetourNbtiPr[j][2] >> RetourNbtiPr[j][1];
	}


	ll tank;
	ll credit = 0;
	int Psum = 0;
	if (T - AllerDiPr[0][0] > AllerDiPr[1][0]  && AllerDiPr[1][1] < AllerDiPr[0][1]  ) {
		tank = T - AllerDiPr[0][0];
		credit += AllerDiPr[0][0];
	} else {
		Psum += (F - T) * AllerDiPr[0][1];
		tank = F;
	}

	for (ll i = 1; i < N; ++i) {
		ll di = AllerDiPr[i][0];
		ll di1 = AllerDiPr[i + 1][0];
		ll pr = AllerDiPr[i][1];
		ll pr1 = AllerDiPr[i + 1][1];

		if (tank - di > di1 && pr1 < pr ) {
			tank = tank - di1;
			credit += di;
		}
		else {
			Psum += (F - di - credit) * pr;
			credit = 0;
			tank = F;
		}
	}


	for (ll i = 0; i < N; ++i) {
		ll di = RetourDiPr[i][0];
		ll di1 = RetourDiPr[i + 1][0];
		ll pr = RetourDiPr[i][1];
		ll pr1 = RetourDiPr[i + 1][1];

		if (tank - di > di1 && pr1 < pr ) {
			Psum += 0 ;
			tank = tank - di1;
			credit += di;
		}
		else {
			Psum += (F - di - credit) * pr;
			credit = 0;
			tank = F;
		}
	}

	int sumt = 0;
	for (ll i = 0; i < A; ++i) {
		sumt += AllerNbtiPr[i][0] * AllerNbtiPr[i][1] + RetourNbtiPr[i][0] * RetourNbtiPr[i][1];
	}
	cout << Psum << endl;
	cout << sumt << endl;
	cout << sumt - Psum;

} 