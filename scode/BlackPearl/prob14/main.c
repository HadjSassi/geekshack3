#include<stdio.h>

int main(){
   scanf("%d %d",&l, &w);
   scanf("%d", &t_size);
   scanf("%d", &t_number);
   
   if ( l)
   
   nbre_t_l=0;
   len_t=1;
   do
   {
       len_t= len_t+1+t_size;
       nbre_t_l= nbre_t+1;
   }
   while (len_t<=l);
   
   nbre_t_w=0;
   wid_t=1;
   do
   {
       wid_t=wid_t+1;
       nbre_t_w=nbre_t_w+1;
   }
   while( wid_t<= w);
} 