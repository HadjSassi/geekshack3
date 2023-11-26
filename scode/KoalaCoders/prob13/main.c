#include <stdio.h>

int pgcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int pgcdl(int l[], int size) {
    if (size == 1) {
        return pgcd(l[0], l[0]);
    }
    if (pgcd(l[0], l[1]) == 1) {
        return 1;
    }
    l[0] = pgcd(l[0], l[1]);
    for (int i = 1; i < size - 1; i++) {
        l[i] = l[i + 1];
    }
    return pgcdl(l, size - 1);
}

void generate(int l[], int size, int comb[][10], int* comb_size) {
    *comb_size = 0;
    comb[*comb_size][0] = 0;
    (*comb_size)++;
    for (int i = 0; i < size; i++) {
        int temp_size = *comb_size;
        for (int j = 0; j < temp_size; j++) {
            for (int k = 0; k < i + 1; k++) {
                comb[*comb_size][k] = comb[j][k];
            }
            comb[*comb_size][i + 1] = l[i];
            (*comb_size)++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int h[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    int d[100][10];
    int d_size[100] = {0};
    int s = 0;
    generate(h, n, d, &d_size[0]);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < d_size[i]; j++) {
            if (pgcdl(d[i], i + 1) != 1) {
                s += pgcdl(d[i], i + 1) * (i + 1);
            }
        }
    }
    printf("%d", s);
    return 0;
}

