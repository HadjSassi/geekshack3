#include<stdio.h>

int main(){
int n,s[100],s1=0,s2=0,i,j,d,k,b;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&d);
for (j=0;j<d;j++)
scanf("%d",&s[j]);
b=d-1;
k=0;

while(k<b){
s1+=s[k];

k++;
if(k!=(b-1)){
    s2+=s[b];
    b--;
}
}
}
printf("%d %d",s1,s2);

}


 