#include<stdio.h>
int min (int T[100]){
    int min1,j;
    min1=T[0];
    for(j=1;j<100;j++){
        if (T[j]<min1){
            min1=T[j];
        }
    }
    return min1;
}
int main(){
    int l,c,nb_obs,i,li,lc,pos_gx,pos_gy,pos_px,pos_py,j,nb_tr;
    scanf("%d %d",&l,&c);
    int T[l][c];
    scanf("\n%d %d",&pos_gx,&pos_gy);
    scanf("%d %d",&pos_px,&pos_py);
    scanf("\n%d",&nb_obs);
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            T[i][j]=0;
        }
    }
    for(i=0;i<nb_obs;i++){
        scanf("%d %d",&li,&lc);
        T[li][lc]=2;
    }
    T[pos_gx][pos_gy]=1;
    T[pos_px][pos_py]=1;
   // int trans[100];
   // i=0;
  //  do{
    do {
        if ((pos_gx>pos_px)&&(pos_gy>pos_py)){
           if (T[pos_gx-1][pos_gy-1]!=2){
            pos_gx-=1;
            pos_gy-=1;
            nb_tr+=1;
                  }
            }
        else if ((pos_gx>pos_px)&&(pos_gy<pos_py))   {
            if (T[pos_gx-1][pos_gy+1]!=2){
                pos_gx-=1;
                pos_gy+=1;
                nb_tr+=1;
                
            }
            }
        else if ((pos_gx<pos_px)&&(pos_gy<pos_py))   {
             if (T[pos_gx+1][pos_gy+1]!=2){
                 pos_gx+=1;
                 pos_gy+=1;
                 nb_tr+=1;
             }
        } 
        else if ((pos_gx<pos_px)&&(pos_gy>pos_py)){
            if (T[pos_gx+1][pos_gy-1]!=2){
                pos_gx+=1;
                pos_gy-=1;
                nb_tr+=1;
            }
        }
        else if (pos_gx >pos_px) {
            if (T[pos_gx-1][pos_gy]!=2){
                pos_gx-=1;
                nb_tr+=1;
                
            }
        }
        else if (pos_gx<pos_px){
            if (T[pos_gx+1][pos_gy]!=2){
                pos_gx+=1;
                nb_tr+=1;
            }
        }
        if (pos_gy>pos_py){
            if (T[pos_gx][pos_gy-1]!=2){
                pos_gy-=1;
                nb_tr+=1;   
            }
        }
        else if (pos_gy<pos_py){
            if (T[pos_gx][pos_gy+1]!=2){
                pos_gy+=1;
                nb_tr+=1;
            }
        }
        else 
            return 0;
    }while((pos_gx!=pos_px)||(pos_gy!=pos_py));
   // trans[i]=nb_tr;
   // i+=1;
   // }while();
    printf("%d",nb_tr);
    return 0; }   