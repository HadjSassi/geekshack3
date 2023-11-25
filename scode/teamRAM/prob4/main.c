
#include <stdio.h>

int main() {
    int l,h,x,y,vx,vy,K;
    int xfin,yfin;
    do {
        scanf("%d ",&l);
        scanf("%d ",&h);
    } while (l>10000 || l<1 || h<1 || h>10000) ;
    do {
        scanf("%d ",&K);
    } while (K<1 || K>10000);
    do {
        scanf("%d",&x);
        scanf("%d",&y);
    } while(x<1 || x>10000 || y<1 || y>10000);
    do {
        scanf("%d",&vx);
        scanf("%d",&vy);
    } while(vx<1 || vx>10000 || vy<1 || vy>10000);
    while (K!=0) {
        if(x+vx>l || y+vy>h){
            if(x+vx>l) {
               x=l; 
            }
            if (x+vy>h) {
                y=h;
            }
            K-=1;
            
        }
        else if (x+vx<0 || y+vy<0) {
            if(x+vx<0) {
                x=0;
            }
            if(y+vy<0) {
                y=0;
            }
            K-=1;
        }
        else {
            x+=vx;
            y+=vy;
        }
        
    }
    xfin=(int)x;
    yfin=(int)y;
    printf("%d %d",xfin,yfin);
   
    return 0;
}