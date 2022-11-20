#include<stdio.h>

int nb=0;
int i=0;
int j=0;
int main(){
    int n,a;
scanf("%d",&n);
char **T;
char **p=T;
char ch[100];
for(a=0;a<n;a++){
    
    getline(&T[i], &capacity, stdin);
    
    p+a=ch;
}
int m=sizeof(ch);
while(i<n)
{
    while(j<m)
    {
        if ((T[i][j]==1)&&(i>=1)&&(j>=1))
        {
             if (T[i-1][j]==2){
                 if (T[i-1][j-1]==3){
                     if (T[i][j-1]==4){
                         nb+=1;
                         j+=1;}}}

             else if (T[i][j-1]==2){
                  if (T[i-1][j-1]==3){
                      if (T[i-1][j]==4){
                          nb+=1;
                          j+=1;}}}}
        else if ( T[i][j]==1) {
               if (T[i+1][j]==2){
                   if( T[i+1][j+1]==3){
                        if (T[i+1][j]==4){
                            nb+=1;
                            j+=1;}}}

               else if (T[i][j+1]==2){
                   if (T[i+1][j+1]==3){
                       if (T[i+1][j]==4){
                           nb+=1;
                          j+=1;}}}}
    }
    i+=1;
}


     
   
 return 0;
} 