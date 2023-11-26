#include <stdio.h>
#include <stdlib.h>
#define Nmax 6
int main()
{   int n,m,i,j,M[Nmax][Nmax],r=0,y=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&M[i][j]);
            if(M[i][j]==1)
                r++;
            else if(M[i][j]==1)
                y++;
        }
    }
    if(r>y){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(M[i][j]==M[i+1][j]==M[i+2][j]==2)
                    return 2;
                if(M[i][j]==M[i][j+1]==M[i][j+2]==2)
                    return 2;
            }
        }
    }
    if(y>r){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(M[i][j]==M[i+1][j]==M[i+2][j]==1)
                    return 1;
                if(M[i][j]==M[i][j+1]==M[i][j+2]==1)
                    return 1;
            }
        }
    }
    return 0;
}
