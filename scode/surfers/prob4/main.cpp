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


    std::cout << x << " " << y << std::endl;

    return 0;
}
