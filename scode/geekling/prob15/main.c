#include<stdio.h>
#include<stdlib.h>

int main(){ 
    int x,y;
    printf("give me a line containing 2 integers x and y\n");
    int decimal_num, binary_num = 0, i = 1, remainder;
    scanf("%d %d", &x, &y);  // add this line to get input values for x and y
    for(decimal_num=x;decimal_num<=y;decimal_num++)
      {  // add missing curly braces
        while (decimal_num != 0) 
        {do 
           {remainder=decimal_num%2;
           int k,d;
           if (remainder==0) k++;}while((decimal_num /2)!=0);}
        if (k==1) {d++;
         printf("the number is %d\n",d);}
    return (0);
} }