#include <stdio.h>
#include <string.h>

int count_delicious_substrings(char *s) {
int count = 0;
int s_len = strlen(s);

for (int i = 0; i < s_len; i++) {
 for (int j = i + 1; j <= s_len; j++) {

 if (strncmp(s + i, "chak", 4) == 0 && strncmp(s + j - 6, "chouka", 6) == 0) {
 count++;
 }
 }
 }

return count;
}

int main() {
char s[1001];
scanf("%s", s);

int result = count_delicious_substrings(s);
printf("%d\n", result);

return 0;
}