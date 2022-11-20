#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct{
    int P;
    int R;
}machine;

int main(){
    int budget,nb_type,i,k,j,nbo,x,y,sum=0,l=0;
    char*ch0,*ch1,*ch2;
    machine M[10];
    ch0=(char *) malloc( sizeof( char) * 10 );
    ch1=(char *) malloc( sizeof( char) * 10 );
    ch2=(char *) malloc( sizeof( char) * 10 );
    scanf("%d",&budget);
    scanf("%d",&nbo);
    fgets(ch0,10,stdin);
    
    for(i=0;i<nbo;i++){
        fgets(ch0,10,stdin);
        
    strcpy(ch1,"");
    ch2="";
    
    strncpy(ch1,ch0,1);
    x=atoi(ch1);
    M[i].P=x;
    
    if(x==0 && strcmp(ch1,"0")!=0) {printf("%s","INPUT_ERROR");exit(0);} ; 
    
    ch2=strchr(ch0+1,' ');
    y=atoi(ch2+1);
    M[i].R=y;
    }
    
    
    
    for(i=0;i<nbo;i++){
       j=i;
       sum=0;
       l=0;
       while(sum<budget && j<nbo){
           sum+=M[j].P*j;
           l+=M[j].R;
           j++;
       }
        
    }
    printf("%d",l);
    return 0;
}   