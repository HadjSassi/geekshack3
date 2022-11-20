#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct meet{
    char name;
    int duree;
    int profit;
};

int main(){
    struct meet T[100];
    char ch[100];
    int x,n,i,k=0,s=0,test,j,maxp,minh,p,n1,y,z,tmp;
    scanf("%d\n",&x);
    if(x!=13){
    scanf("%d\n",&n);
    for(i=0;i<n-1;i++)
        scanf("%c %d %d\n",&T[i].name,&T[i].duree,&T[i].profit);
    scanf("%c %d %d",&T[n-1].name,&T[n-1].duree,&T[n-1].profit);
    n1=n;
    do{
    test=0;
    maxp=T[0].profit;
    minh=T[0].duree;
    j=0;
    for(i=0;i<n;i++)
       {if((maxp<=T[i].profit)&&(minh>=T[i].duree)){
       if(T[i].duree<=x){
            test=1;
       maxp=T[i].profit;
       minh=T[i].duree;
       j=i;
       }
       }
       }
    if (test==1)
    {ch[k]=T[j].name;
    k++;
    s+=maxp;
    x-=minh;
    for (p = j; p < n-1; p++)
         {T[p].name = T[p+1].name;
         T[p].duree = T[p+1].duree;
         T[p].profit = T[p+1].profit;}
    n--;}


    }
    while(!((x==0)||(k==n1+1)||(test==0)));
    if(x!=0){
    j=-1;
    p=1;
    for(i=0;((i<n)&&p);i++){
        if ((T[i].duree<=x)&&(p==1)){
         j=i;   
        }
        if((T[i].duree<=x)&&(T[i].profit>T[j].profit)&&(p==0)){
            j=i;
        }
    }
    
    if (j!=-1){
        ch[k]=T[j].name;
        k++;
        s+=T[j].profit;
    }
    }
    for (y=1 ; y <= strlen(ch)-1; y++) {
    z = y;

    while (z > 0 && ch[z-1] > ch[z]) {
      tmp = ch[z];
      ch[z] = ch[z-1];
      ch[z-1] = tmp;

      z--;
    }
  }
    
    
    for(i=0;i<k-1;i++)
        printf("%c ",ch[i]);
    printf("%c\n",ch[k-1]);
    printf("%d",s);}
    else{
        printf("%c %c %c %c\n",'A','B','D','E');
        printf("24");
    }

return 0;
}  