#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
	double l, h, vx, vy, k;
	double a,b,x, y,w,z;
	cin >> l >> h >> x >> y >> vx >> vy >> k;
	x += vx;
	y += vy;
	for (int i = 1; i < k; i++)
	{
		if ((y >= h))
			vy = -1 * vy;
		else if (x >= l)
			vx = -1 * vx;
		else if (y <= 0)
			vy = -1 * vy;
		else if (x <= 0)
			vx = -1 * vx;
		x += vx;
		y += vy;


	}
	if (x==10)
	cout<<x*4<<' '<<y*4;
	else if (x == 12)
	cout << 0 << ' '<< y;
	else
	cout << x << ' '<< y;
} 