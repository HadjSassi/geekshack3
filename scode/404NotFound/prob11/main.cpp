#include <stdio.h>
int minimum(float tab[10],int n){
    float min=tab[0];
    int indice=0;
    for(int i=1;i<n;i++){
        if(tab[i]<min){
            min=tab[i];
            indice=i;
        }
    }
    return indice;
}
int main(){

int capacite,n;
    char t1[10];
    int t2[10];
    int t3[10];
    scanf("%d",&capacite);
    scanf("%d",&n);
    

    for(int i=0;i<n;i++){
    scanf("%s",&t1[i]);
    scanf("%d",&t2[i]);
    scanf("%d",&t3[i]);
    }
    
    
    float t4[n];
    for(int j=0;j<n;j++){
        t4[j]=t3[j]/t2[j];
    }
    
    	int currentWeight = 0;
	int gain=0;
    int m;
    int k;
    while(k<=n){
    m=minimum(t4,n);
    t4[m]=200;
    		if ((currentWeight + t2[m]) <= capacite){
			currentWeight += t2[m];
			gain += t3[m];
		}
		k++;
    printf("%c ",t1[m]);
    } 

    printf("\n%d",gain);
}
 