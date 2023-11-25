#include <stdio.h>
#include <stdbool.h>

int countOnes(int num) {
    int count = 0;
    while (num) {
        num = num & (num - 1);
        count++;
    }
    return count;
}

int main() {
    int x, y;
    while (true) {
        scanf("%d %d", &x, &y);
        if (1 <= x && x <= y && y <= 100000000000000LL) {
            break;
        }
    }

    int c = 0;
    for (int i = x; i <= y; i++) {
        int ones = countOnes(i);
        if (ones == 1) {
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}