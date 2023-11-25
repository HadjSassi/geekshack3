#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define pdd pair<double,double>
double h,w,x,y,vx,vy;
int k;
void print(pdd p){
    cerr << p.f << " " << p.s << endl;
}
int intersection(double line, pdd p1, pdd p2){
    double a = (p1.s - p2.s) / (p1.f - p2.f);
    double b = p1.s - a * p1.f;
    return (line - b) / a;
}

int main(){

    cin >> w >> h >> x >> y >> vx >> vy >> k;

    while(k--){
        double x0 = vx + x;
        double y0 = vy + y;
        pdd p1 = {x,y} , p2 = {x0,y0} , p1r = {y,x} , p2r = {y0,x0};

        if(vx > 0 && vy > 0){
            double ix = intersection(h,p1,p2);
            double iy = intersection(w,p1r,p2r);
            if(ix < w){
                x = ix;
                y = h;
                vy = -vy;
            }else{
                x = w;
                y = iy;
                vx = -vx;
            }
        }else
        if(vx < 0 && vy > 0){
            double ix = intersection(h,p1,p2);
            double iy = intersection(0,p1r,p2r);
            if(ix <= w && ix >= 0){
                x = ix;
                y = h;
                vy = -vy;
            }else{
                x = 0;
                y = iy;
                vx = -vx;
            }
        }else
        if(vx > 0 && vy < 0){
            double ix = intersection(0,p1,p2);
            double iy = intersection(w,p1r,p2r);
            if(ix <= w && ix >= 0){
                x = ix;
                y = 0;
                vy = -vy;
            }else{
                x = w;
                y = iy;
                vx = -vx;
            }
        }else
        if(vx < 0 && vy < 0){
            double ix = intersection(0,p1,p2);
            double iy = intersection(0,p1r,p2r);
            if(ix <= w && ix >= 0){
                x = ix;
                y = 0;
                vy = -vy;
            }else{
                x = 0;
                y = iy;
                vx = -vx;
            }
        }
    }
    cout << x << " " << y << endl;

}