#include<iostream>
using namespace std;
bool isInsideCircle(int cx, int cy, int r, int x, int y) {
   int dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
   if ( dist <= r * r)
      return true;
   else
      return false;
}
int main() {
   int x = 4, y = 4, cx = 1, cy = 1, rad = 6;
   if(isInsideCircle(cx, cy, rad, x, y)){
      cout <<"NO";
   } else {
      cout <<"YES";
   }
}   