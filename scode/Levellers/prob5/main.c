#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i=0,M,N;
    
    
    char ch[10];
    char ch1[10];
    char ch2[10];
    fgets(ch,10,stdin);
    
    strncat(ch1,ch,1);
    M=atoi(ch1);
    ch2=strchr(ch,' ');
    N=atoi(ch2);
    printf("%d",M);
    printf("%d",N);
    
    
    
       

}    