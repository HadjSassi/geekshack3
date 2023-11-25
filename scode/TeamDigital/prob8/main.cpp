// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// possible sum after M operations
int max_sum(int a[], int n, int b[][2], int m)
{

	// Sort the array a in
	// increasing order
	sort(a, a + n);

	// Place all replaceable cards in B
	vector<pair<int, int> > B;
	for (int i = 0; i < m; i++)
		B.push_back({ b[i][1], b[i][0] });

	// Sort vector B in decreasing order
	sort(B.rbegin(), B.rend());

	// To store last unused card of a
	int left = 0;

	// Try to apply all m operations
	for (int i = 0; i < m; i++) {
		int x = B[i].first, y = B[i].second;

		// Try for all applicable cards
		for (int j = 0; j < y; j++) {

			// If current number on card is
			// less than applicable card
			if (a[left] < x) {
				a[left] = x;
				left++;

				if (left == n)
					break;
			}
			else
				break;
		}
	}

	// To store the maximum
	// possible sum
	int ans = 0;

	// Calculate the maximum
	// possible sum
	for (int i = 0; i < n; i++)
		ans += a[i];

	// Return the required answer
	return ans;
}

// Driver code
int main()
{
	int a[] = { 5, 1, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	int b[][2] = { { 2, 3 }, { 1, 5 } };
	int m = sizeof(b) / sizeof(b[0]);

	cout << max_sum(a, n, b, m);

	return 0;
}
