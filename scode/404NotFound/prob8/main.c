#include<stdio.h>

 
int main ()
{ 
  int tab[4] ;
  int min=0,max=0;
 
for (int i = 0; i<4; i++)
  {  scanf("%d",&tab[i]);
    
  }

  
    

    min=tab[0];
    max=tab[2];
    //printf("%d",min);
    //printf("%d",max);
    
    
   if(tab[0]>tab[1]){   
        min=tab[1];
  }
   if(tab[2]<tab[3]){   
        max=tab[3];
  }

printf("%d",max*min);

if(sizeof(tab)<4){
    printf("NO");
}
  return 0;
}