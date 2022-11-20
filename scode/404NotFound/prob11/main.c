
#include <stdio.h>  
#include <stdlib.h> 
int main(){
  
  int tab[10], nbr, i;  
  
  printf("Entrez le nombre à convertir: ");  
  scanf("%d",&nbr);  
  
  for(i=0; nbr > 0; i++)  
  {  
    tab[i] = nbr%2;  
    nbr = nbr/2;  
  } 
  
  printf("\nLe nombre binaire est = ");
  
  for(i=i-1; i >= 0; i--)  
  {  
    printf("%d",tab[i]); 
    if(tab[i]==100){
        printf("need_backup"); 
    }
  }  
  
  return 0;
}