#include<stdio.h>
#include<math.h>
#define nmax 100

int main(){
    int t[nmax][4] ;
    int n,f,t,a,d_i,c_i,i,j,p_ir,nb_ir,nb_ia,p_ia,s,c,p;
    i=0;
    
    do{
        
        scanf("%d",&n);
        
        
    } 
    while(n<0 || n>50001);
    t[0][0]=n;
   
    do{
        scanf("%d",&f);
        
    } 
   while(f<0 || f>1000001);
   t[0][1]=f;
   do{
        scanf("%d",&t);
        
    } 
    while(t<0 || t>f);
   t[0][2]=t;
   do{
        scanf("%d",&a);
        
    } 
    while(a<0 || a>50001);
    t[0][3]=a;
   for(i=1;i<n;i++,printf("\n");){
        do{
           scanf("%d",&d_i);
        
        }  while(d_i<0 || d_i>l);
       t[i][0]=d_i;
       do{
         scanf("%d",&c_i);
        
        } while(c_i<1 || c_i>1000000);
       t[i][1]=c_i; 
       do{
         scanf("%d",&d_i);
        } while(d_i<0 || d_i>l);
       t[i][2]=d_i;
       do{
          scanf("%d",&c_i);
        } while(c_i<1 || c_i>1000000);
        t[i][2]=c_i;
        do{
           scanf("%d",&d_i);
        } while(d_i<0 || d_i>l);
        t[i][3]=d_i;
    }
   for(i=n;i<n+a;i++){
       do{
           scanf("%d",&nb_ia);
       }while(nb_ia<1 || nb_ia>50);
       t[i][0]=nb_ia;
       do{
           scanf("%d",&p_ia);
       }while(p_ia<1 || p_ia>10000);
       t[i][1]=p_ia;
       do{
           scanf("%d",&nb_ir);
       }while(nb_ir<1 || nb_ir>50);
       t[i][2]=nb_ir;
       do{
           scanf("%d",&p_ir);
       }while(p_ir<1 || p_ir>10000);
       t[i][3]=p_ir;
    }
    s=0;
    c=0;
    p=0;
    for(i=1;i<n+1;i++){
        s+=((t[0][1] -(t[0][3] -t[i][0] ))*t[i][1])*2 ;
    }
    for(i=n+1;i<n+a+1;i++){
        c+=t[i][0]*t[i][1]+t[i][2]*t[i][3];
    }
    p=c-s;
    printf("%d",s);
    printf("%d",c);
    printf("%d",p);
    
    return 0 ;
   
} 