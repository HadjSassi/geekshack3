#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    if(x<1 || x>14)
    {printf("NOT_CLEAR")}
    else {
        if(x==1)
        printf("take_position");
        if(x==2)
        printf("run");
        if(x==3)
        printf("run");printf("take_position");
        if(x==4)
        printf("need_backup");
        if(x==5)
        {printf("need_backup");
        printf("take_position");}
        if(x==6)
        {printf("need_backup");
        printf("run");
        printf("take_position");}
        
    return 0;
} 