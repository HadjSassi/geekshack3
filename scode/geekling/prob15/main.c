#include<stdio.h>
#include<stdlib.h>

int bitnum(int num);

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    
    int d = 0;
    
    for(int num = x; num <= y; num++) {
        if(bitnum(num) == 1) {
            d++;
            printf("%d\n", d);
        }
    }
    
   
    
    return (0);
}

int bitnum(int num) {
    int count = 0;
    
    while(num) {
        num = num & (num - 1);
        count++;
    }
    
    return count;
}