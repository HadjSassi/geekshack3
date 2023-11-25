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
s2+=s[b];
while(k<b){
s1+=s[k];

k++;
if(k!=(b-1)){
b--;s2+=s[b];}
}
}
printf("%d\n%d",s1,s2);
return 0;
}


 