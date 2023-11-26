#include <stdio.h>
#include <stdlib.h>
#define Nmax 7
int main()
{   int n,m,i,j,M[Nmax][Nmax],r=0,y=0,t=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&M[i][j]);
            if(M[i][j]==1)
                r++;
            else if(M[i][j]==2)
                y++;
            else if(M[i][j]==0)
                t++;
        }
    }

    if(t==n*m || t==36)
        printf("0");


    else if(r>y){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if((M[i][j]==2)&&(M[i+1][j]==2)&&(M[i+2][j]==2)){
                        printf("2");

                    }
                else if((M[i][j]==2)&&(M[i][j+1]==2)&&(M[i][j+2]==2))
                    {
                        printf("2");
                    }
            }
            if(M[i][i]==2)
                {
                    printf("2");
                }
        }
    }
    else if(y>r){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if((M[i][j]==1)&&(M[i+1][j]==1)&&(M[i+2][j]==1)){
                        printf("1");
                    }
                else if((M[i][j]==1)&&(M[i][j+1]==1)&&(M[i][j+2]==1)){
                        printf("1");
                    }
            }
            if(M[i][i]==1){
                        printf("1");
                        break;
                 }
        }

}
else if(r==y){
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if((M[i][j]==1)&&(M[i+1][j]==1)&&(M[i+2][j]==1)&&(M[i+3][j]==1)){
                        printf("1");
                    }
                else if((M[i][j]==1)&&(M[i][j+1]==1)&&(M[i][j+2]==1)&&(M[i][j+3]==1)){
                        printf("1");
                    }
                else if((M[i][j]==2)&&(M[i+1][j]==2)&&(M[i+2][j]==2)&&(M[i+3][j]==2)){
                        printf("2");
                    }
                else if((M[i][j]==2)&&(M[i][j+1]==2)&&(M[i][j+2]==2)&&(M[i][j+3]==2)){
                        printf("2");
                    }
            }
            if(M[i][i]==1){
                        printf("1");
                        break;
                 }
            else if(M[i][i]==2){
                        printf("2");
                        break;
                 }
        }
}


return 0;}

 