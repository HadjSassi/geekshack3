#include<stdio.h>
#include<string.h>


int main(){
    char mot[1000];
    fgets(mot,1000,stdin);
    int i,j,x,n;
    x=strlen(mot);
    for(i=0;i<x-6;i++)
    
    {if(mot[i]=='c'&&mot[i+1]=='h'&& mot[i]&&mot[i+2]=='a'&&mot[i+3]=='k')
     {for(j=i+4;j<x;j++){
        if(mot[j]=='c'&&mot[j+1]=='h'&& mot[j+2]=='o'&&mot[j+3]=='u'&&mot[j+4]
        &&mot[j+5]=='k'&&mot[j+6]=='a')
        n++;}}}
    return n;
    
} 