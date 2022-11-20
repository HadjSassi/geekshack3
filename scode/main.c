#include<stdio.h>

int main(){
    int o;
scanf(%d,&o);
char **T;
char ** p=T;
for(a=0;a<o;a++){
    char ch[100];
    fgets(ch, 100, stdin);
    p+a=ch;
    
    
    
    
    
}
m=sizeof(ch);
int nb=0;
int i=0;
int j=0;
while(i<n)
{
    while(j<m)
    {
        if ((T[i][j]==1)and(i>=1)and(j>=1))
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
print(nb);

     
   
 return 0;
} 