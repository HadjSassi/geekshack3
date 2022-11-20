#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
   int x, i, j ,n,cpt=0;
   scanf("%d", &n);
   int tableau[n][4]; 
 
    for(i=0; i<n; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%d", &x);
            tableau[i][j] = x ;
        }
    }
 
    for(i=0; i<n; i++)
    {
        for(j=0; j<4; j++)
        {
            if (( tableau[i][j] == 1 && tableau[i][j-1] == 2 
            && tableau[i+1][j-1] == 3  && tableau[i+1][j] == 4)
          || (tableau[i][j] == 1 && tableau[i][j+1] == 2 
            && tableau[i+1][j+1] == 3  && tableau[i+1][j] == 4)  
           || (tableau[i][j] == 1 && tableau[i+1][j] == 2 
            && tableau[i+1][j-1] == 3  && tableau[i-1][j] == 4)  
            || (tableau[i][j] == 1 && tableau[i+1][j-1] == 2 
            && tableau[i][j-1] == 3  && tableau[i+1][j] == 4)
            
            || (tableau[i][j] == 1 && tableau[i+1][j] == 2 
            && tableau[i+1][j+1] == 3  && tableau[i][j+1] == 4)
            
            || (tableau[i][j] == 1 && tableau[i+1][j+1] == 3
            && tableau[i+1][j] == 2  && tableau[i][j+1] == 4)
            
            || (tableau[i][j] == 1 && tableau[i-1][j+1] == 3
            && tableau[i][j+1] == 2  && tableau[i-1][j] == 4)
            || (tableau[i][j] == 1 && tableau[i+1][j-1] == 3
            && tableau[i+1][j] == 2  && tableau[i][j-1] == 4)
            
           ) {
                cpt++;
            }
        }
    }
 printf("%d",cpt);

  return 0;
} 