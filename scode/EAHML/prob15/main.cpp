#include<iostream>

using namespace std;

#include<stdio.h>
#include<string.h>
int fct(int a,int b,int c,int d){
    if(((a*c==8)&&(b*d==3))||((a*c==3)&&(b*d==8)))
    return 1;
    else
    return 0;
}

int main(){
    int t[100][100];
    int n,i,s,j,k;
    char ch[100];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        gets(ch);
        char *ptr = strtok(ch," ");
        
        k=0;
	while(ptr != NULL)
	{
	    t[i][k]=*ptr-48;
		ptr = strtok(NULL," ");
		k++;
	}
        
        
    }
    s=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<k-1;j++){
            if(fct(t[i][j],t[i][j+1],t[i+1][j+1],t[i+1][j]))
            s++;
        }
    }
    printf("%d",s);
    
    return 0;
} 