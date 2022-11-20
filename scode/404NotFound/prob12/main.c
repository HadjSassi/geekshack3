#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void obstacle(int tab[100][100],int Nb_obstacle){
    int x,y;
    for(int i=0; i<Nb_obstacle; i++){
        printf( "x et y de l'obstacle %d ",i+1);
        scanf( "%d", &x);
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
    printf( "nb lignes et nb colonnes ");
    scanf( "%d", &Nb_L);
    scanf( "%d", &Nb_c);
    for(int i=0; i<Nb_L; i++){
    for(int j=0; j<Nb_c; j++)
        tab[i][j]=0;
}
    
        int Pos_Gx,Pos_Gy;
    printf( "x et y de ghost ");
    scanf("%d", &Pos_Gx);
    scanf("%d", &Pos_Gy);
    tab[Pos_Gx][Pos_Gy]=1;
    
    int Pos_Px,Pos_Py;
    printf( "x et y de player ");
    scanf("%d", &Pos_Px);
    scanf("%d", &Pos_Py);
    tab[Pos_Px][Pos_Py]=3;
    printf( "nb obstacle ");
    scanf( "%d", &Nb_obstacle);
    obstacle(tab, Nb_obstacle );
    
    
    float distance_droite,distance_gauche, distance_up, distance_down=1000;
    float min=1000;
    float A[4];

   //dans un boucle à chaque fois :
   while(min!=0){
    if(tab[Pos_Gx+1][Pos_Gy]!=2){distance_droite = sqrt(pow(Pos_Py - (Pos_Gx+1),2) + pow((Pos_Px - Pos_Gy),2));}
    if(tab[Pos_Gx-1][Pos_Gy]!=2){distance_gauche = sqrt(pow(Pos_Py - (Pos_Gx-1),2) + pow((Pos_Px - Pos_Gy),2));}
    if(tab[Pos_Gx][Pos_Gy+1]!=2){distance_up = sqrt(pow((Pos_Py - Pos_Gx),2) + pow((Pos_Px - (Pos_Gy+1)),2));}
    if(tab[Pos_Gx][Pos_Gy-1]!=2){distance_down = sqrt(pow((Pos_Py - Pos_Gx),2) + pow((Pos_Px - (Pos_Gy-1)),2));}
    A[0]=distance_droite;
    A[1]=distance_gauche;
    A[2]=distance_up;
    A[3]=distance_down;
    min= minimum(A);
    printf("min = %f ",min);
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
   //fin boucle
  
    
    
    printf("\n resultat");
    printf("%d",cnt);
    return 0;
} 