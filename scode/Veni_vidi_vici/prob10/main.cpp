#include <bits/stdc++.h>
using namespace std;

double  solve(double r1, double r2, double d) {
    if (d >= r1 + r2) {
        return 0;
    } else if (d <= abs(r1 - r2)) {
        double smallerR = (r1 < r2) ? r1 : r2;
        return (4.0 / 3.0) * M_PI * pow(smallerR, 3);  } else {
        double x = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * d);
        double y = d - x;
        double h1 = r1 - x;
        double h2 = r2 - y;
        double volume1 = (1.0 / 3.0) * M_PI * (3 * h1 * h1 * r1 - pow(h1, 3));
        double volume2 = (1.0 / 3.0) * M_PI * (3 * h2 * h2 * r2 - pow(h2, 3));
        return volume1 + volume2;
    }
}

int main() {
    double x0,y0,z0,r0;
    double x1,y1,z1,r1;
    cin >> x0 >> y0 >> z0 >> r0 >> x1 >> y1 >> z1 >> r1;

    double d = sqrt(pow(x0 - x1,2)+pow(y0 - y1,2)+pow(z0 - z1,2));
    cout << fixed;
    cout << setprecision(3);
    cout << floor(1000*solve(r0,r1,d))/1000;
    return 0;
}


   