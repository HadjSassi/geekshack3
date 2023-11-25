
#include <bits/stdc++.h>
using namespace std;
void checkWinner(int N, int K)
{
	if (N % (K + 1)) {
		cout << "A";
	}
	else {
		cout << "B";
	}
}
int main()
{
	int N ;
	int K ;
	cin>>N ;
	cin>>K ;
	checkWinner(N, K);
}
