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
	a =double( vy / vx);
	b = y - a * x;
	for (int i = 0; i < k; i++)
	{
		double x1, y1, x2, y2, x3, y3, x4, y4 ;
		// 1 er cas 

		x1 = 0;
		y1 = a * x1 + b;

		// 2 eme 
		x2 = l;
		y2 = a* x2 + b;

        // 3 eme

		y3 = 0;
		x3 = (y3 - b) / a;

		// 4 eme cas 

		y4 = h;
		x4 = (y4 - b) / a;

		for (int j = 0; j < 4; j++)
		{
			if ((y1 >= 0) && (y1 <= h) && (y1 != y))
			{
				a = -1 * a;
				b = y1 - (a * x1);
				w = x1;
				z = y1;
	
				break;
			}
			else if ((y2 >= 0) && (y2 <= h) && (y2 != y))
			{
				a = -1 * a;
				b = y2 - (a * x2);
				w = x2;
				z = y2;
				break;
			}
			else if ((x3 >= 0) && (x3 <= l) && (x3 != x))
			{
				a = -1 * a;
				b = y3 - (a * x3);
				w = x3;
				z = y3;
				break;
			}
			else if ((x4 >= 0) && (x4 <= l) && (x4 != x))
			{
				a = -a;
				b = y4 - (a * x4);
				w = x4;
				z = y4;
				break;
			}


		}

	}
	cout << floor(w) << ' ' << floor(z) << endl;
}