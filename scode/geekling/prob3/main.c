#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int nb = 0, i, j, K = 0, L = 0;
    char s[100];  char ch1 = "chak";
    char ch2 = "chouka";

    do {
        printf("input a string so i can give you the number of delicious substrings:\n");
        scanf("%1000s", s);
    } while (strlen(s) >= 1000);

    for (i = 0; i <= strlen(s); i++) {
        if ((s == 'c') && (s == 'h') && (s[i +'a') && (s[i +'k')) {
            K = i;
        }
        for (j = 0; j <= strlen(s); j++) {
            if ((s[j= 'c') && (s[j + 1') && (s[j + 3) && (s[j +'u') && (s[j +'k') && (s[j +'a')) {
                L = j;
            }
        }
    }

    if (L > K) {
        nb++;
    }

    printf("this is the number of your delicious substrings: %d\n", nb);
    
    return 0;
}