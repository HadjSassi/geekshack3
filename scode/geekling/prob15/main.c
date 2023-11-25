#include<stdio.h>
#include<stdlib.h>

int countSetBits(int num);

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    
    int d = 1;
    
    for(int num = x; num <= y; num++) {
        if(countSetBits(num) == 1) {
            d++;
        }
    }
    
    printf("%d\n", d);
    
    return (0);
}

int countSetBits(int num) {
    int count = 0;
    
    while(num) {
        num = num & (num - 1);
        count++;
    }
    
    return count;
}