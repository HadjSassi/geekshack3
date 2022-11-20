#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i,j,M,N,Mat[10][10],Pos_Gx,Pos_Gy,Pos_Px,Pos_Py,nbo,x,y,go;
    
    char*ch,*ch0;
    char*ch1;
    char*ch2;
    ch=(char *) malloc( sizeof( char) * 10);
    ch0=(char *) malloc( sizeof( char) * 10);
    ch1=(char *) malloc( sizeof( char) * 10);
    ch2=(char *) malloc( sizeof( char) * 10);
    fgets(ch,10,stdin);
    strcpy(ch1,"");
    strcpy(ch2,"");
    
    strncpy(ch1,ch,1);
    N=atoi(ch1);
    
    ch2=strchr(ch,' ');
    M=atoi(ch2+1);
    
    for(i=0;i<N;i++){
        
       for(j=0;j<M;j++){
           Mat[i][j]=0;
       }}
       
      
    fgets(ch0,10,stdin);
   
    
    
    strcpy(ch1,"");
    strcpy(ch2,"");
    
    strncpy(ch1,ch0,1);
    Pos_Gx=atoi(ch1);
    
    ch0=strchr(ch0,' ');
    strncpy(ch1,ch0+1,1);
    Pos_Gy=atoi(ch1);
    
    
    Mat[Pos_Gy][Pos_Gx]=-1;
    
    ch0=strchr(ch0+1,' ');
    strncpy(ch1,ch0+1,1);
    Pos_Px=atoi(ch1);
    
    
    ch0=strchr(ch0+1,' ');
    strncpy(ch1,ch0+1,1);
    Pos_Py=atoi(ch1);
    
    
    Mat[Pos_Py][Pos_Px]=1;
    
    scanf("%d",&nbo);
    fgets(ch0,10,stdin);
    for(i=0;i<nbo;i++){
        fgets(ch0,10,stdin);
        
       strcpy(ch1,"");
    ch2="";
    
    strncpy(ch1,ch0,1);
    x=atoi(ch1);
    
    if(x==0 && strcmp(ch1,"0")!=0) {printf("%s","INPUT_ERROR");exit(0);} ; 
    
    ch2=strchr(ch0+1,' ');
    y=atoi(ch2+1);
   
    
    Mat[y][x]=-2;
        
    }
    
    
     go=4;
      for(i=0;i<N;i++){
         
       for(j=0;j<M;j++){
         
          if(Mat[i][j]==1){
              if(i==0) go--;
              if(j==0) go--;
              if(Mat[i+1][j]!=0) go--;
              if(Mat[i][j+1]!=0) go--;
          }
          
             
     
       }
     
     
    
     }
    
    
    
    
    
    
    
    
    
    
    printf("%d",go);
    
    return 0;
       


    
    
    
    
    
    
    
    
    
       

}      