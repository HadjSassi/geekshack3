#include <stdio.h>

int main() {
    int min, max;
    scanf("%d %d", &min, &max);
    int k = 0;
    for (int i = min; i <= max; i++) {
        char ch[32];
        sprintf(ch, "%d", i);
        int count = 0;
        for (int j = 0; ch[j] != '\0'; j++) {
            if (ch[j] == '0') {
                count++;
            }
        }
        if (count == 2) {
            k++;
        }
    }
    printf("%d\n", k);
    return 0;
}