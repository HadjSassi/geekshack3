#include<stdio.h>
#include<string.h>

int main(){
    int x,i,c,j,n,d;
    char ch[x][] ;
    char c1="brmain";
    scanf("%d",&x) ;
    for(i=0;i<x;i++)
    {
        scanf("%s",&ch[i]) ;
        printf("\n");
	   }
	  c=0; 
     for(i=0;i<x;i++)
    {
	    j=0;
     	while(j<7){
		   if(ch[i][j] == c1[j])
              j++;
          
	}
	if( j == 6)
	   c++;
	
	}
	for(i=0;i<c;i++){
		for(n=c+1;n<=x;n++){
		
    
	    j=0;
	    d=0;
     	while(j<strlen(ch[n])){
		    if(ch[i][d] == ch[n][j]){
		    	j++;
		    	d++;
			}
            else
              j++;
            
            
	}
	if (d==strlen(ch[n]))
	   printf("%s",ch[n]);
	if(d==(strlen(ch[n])-1))  
	    printf("%s  :M",ch[n]) ;
	 else
	    printf("%s  :u",ch[n]) ;  
	  
		
		}
		
		
	}
	
	
    return 0;
} 