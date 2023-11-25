#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
	long long n, m;
	cin >> n >> m;
	vector <long long > ali;
	vector <long long > iheb;
	for (long long i = 0; i < n; i++)
	{
		long long x, y;
		double d1 = 0;
		cin >> x >> y;
		d1 = sqrt(x * x + y * y);
		ali.push_back(d1);
		
	}
	for (long long  i = 0; i < m; i++)
	{
		long long x, y;
		double d2 = 0;
		cin >> x >> y;
		d2 = sqrt(x * x + y * y);
		iheb.push_back(d2);
	}
	double minali=0, maxali=0, miniheb=0, maxiheb=0;

	minali = *min_element(ali.begin(), ali.end());
	maxali = *max_element(ali.begin(), ali.end());
	miniheb = *min_element(iheb.begin(), iheb.end());
	maxiheb = *max_element(iheb.begin(), iheb.end());
	if (minali> maxiheb)
		cout << "YES" << endl;
	else if (miniheb > maxali)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

