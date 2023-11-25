#include<stdio.h>
#include<stdlib.h>
int main(){ 
    int x,y;
    {printf("give me a line containing 2 integers x and y\n");
    }
    ///////////////////////////////////
    int decimal_num, binary_num = 0, i = 1, remainder;
    for(decimal_num>=x;decimal_num<=y;decimal_num++)
    while (decimal_num != 0) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    printf("Binary number: %d\n", binary_num);
 char Bin[50]; 
    sprintf(Bin, "%d",Binary number); 
    int k=0;/*le nombre des 0 dans la repr BIN*/
    int d=0,j;/*le nombre des années contenant 0 en repre BIN*/
    for(j=0;j<=50;j++)
     if (Bin[j]==0) k++;
      if (k==1) d++; 
    printf("the number is %d",d);
    return 0;
} 