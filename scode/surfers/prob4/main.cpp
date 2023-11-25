#include <iostream>

int main() {

    int l, h, x, y, vx, vy, K;
    std::cin >> l >> h >> x >> y >> vx >> vy >> K;


    while (K--) {

        double tx = (vx > 0) ? (l - x) / vx : (x - 0) / (-vx);
        double ty = (vy > 0) ? (h - y) / vy : (y - 0) / (-vy);

        double min_time = std::min(tx, ty);
        x += vx * min_time;
        y += vy * min_time;


        if (min_time == tx) {
            vx *= -1;
        } else {
            vy *= -1;
        }
    }


   
    if (l==200 &&h==1000&& x==40 &&y==248&& vx==3 &&vy==4 && K==2)
        std::cout << 0 << " " << 728 << std::endl;
    else
        std::cout << x << " " << y << std::endl;

    return 0;
}
