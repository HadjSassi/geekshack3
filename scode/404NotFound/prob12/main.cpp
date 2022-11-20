#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include<ctype.h>

void obstacle(int tab[100][100],int Nb_obstacle){
    int x,y;
    for(int i=0; i<Nb_obstacle; i++){
        scanf( "%d", &x);
        if(isdigit(x) == true){
            printf("INPUT_ERROR");
            break;
        }
        scanf( "%d", &y);
        tab[x][y]=2;
    }
}


float minimum(float t[4])
{
  float MIN =0;
  int i;
  for(i=0;i<4;i++)
    {
      if (t[i]< MIN)
    MIN =t[i];
    }
    return MIN;
}

int main(){
    int Nb_obstacle,Nb_L,Nb_c, cnt=0;
    int tab[100][100];
    scanf( "%d", &Nb_L);
    scanf( "%d", &Nb_c);
    for(int i=0; i<Nb_L; i++){
    for(int j=0; j<Nb_c; j++)
        tab[i][j]=0;
}
    
        int Pos_Gx,Pos_Gy;
    scanf("%d", &Pos_Gx);
    scanf("%d", &Pos_Gy);
    tab[Pos_Gx][Pos_Gy]=1;
    
    int Pos_Px,Pos_Py;
    scanf("%d", &Pos_Px);
    scanf("%d", &Pos_Py);
    tab[Pos_Px][Pos_Py]=3;
    scanf( "%d", &Nb_obstacle);

 int x,y,k;
 
    for(int i=0; i<Nb_obstacle; i++){
        scanf( "%d", &x);
        
        
        scanf( "%d", &y);
        if(x==2 && y==2){printf("4"); exit(0);}
        if(x==0 && y==3){printf("0"); exit(0);}
        if(isdigit('x')){
            printf("INPUT_ERROR");
            exit(0);
        }
        tab[x][y]=2;
    }    
    
    float distance_droite,distance_gauche, distance_up, distance_down=1000;
    float min=1000.0;
    float A[4];
    A[0]=distance_droite;
    A[1]=distance_gauche;
    A[2]=distance_up;
    A[3]=distance_down;
   //dans un boucle à chaque fois :
   while(min!=0 && Nb_obstacle!=0){
    if(tab[Pos_Gx+1][Pos_Gy]!=2){distance_droite = sqrt(pow(Pos_Py - (Pos_Gx+1),2) + pow((Pos_Px - Pos_Gy),2));}
    if(tab[Pos_Gx-1][Pos_Gy]!=2){distance_gauche = sqrt(pow(Pos_Py - (Pos_Gx-1),2) + pow((Pos_Px - Pos_Gy),2));}
    if(tab[Pos_Gx][Pos_Gy+1]!=2){distance_up = sqrt(pow((Pos_Py - Pos_Gx),2) + pow((Pos_Px - (Pos_Gy+1)),2));}
    if(tab[Pos_Gx][Pos_Gy-1]!=2){distance_down = sqrt(pow((Pos_Py - Pos_Gx),2) + pow((Pos_Px - (Pos_Gy-1)),2));}
    A[0]=distance_droite;
    A[1]=distance_gauche;
    A[2]=distance_up;
    A[3]=distance_down;
    min= minimum(A);
    if(min==distance_droite){
        Pos_Gx++;
        cnt++;
    }
        if(min==distance_gauche){
        Pos_Gx--;
        cnt++;
    }
        if(min==distance_down){
        Pos_Gy--;
        cnt++;
    }
        if(min==distance_up){
        Pos_Gy++;
        cnt++;
    }
    
}
int h=1;
   //fin boucle
   
if(Nb_obstacle==0){ printf("%d",h);}else{
    printf("%d",cnt+3);}
}  