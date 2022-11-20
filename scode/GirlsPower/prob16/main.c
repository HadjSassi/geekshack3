#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int chainenum(char ch[]){
    int l,i;
    l=strlen(ch);
    for(i=0;i<l;i++){
        if(ch[i]=='1'||ch[i]=='2'||ch[i]=='3'||ch[i]=='4'||ch[i]=='5'||ch[i]=='5'||ch[i]=='6'||ch[i]=='7'||ch[i]=='8'||ch[i]=='9'||ch[i]=='0')
            return 1 ;
            return 0 ;
        
    }
}

int main(){
    char b[20],n[20],pi[20],ri[20];
    int i,l,x,s;
        scanf("%s",&b);
        while ( chainenum(b)==0){
            printf("INPUT_ERROR");
            scanf("%s",&b);
            
        }
        scanf("%s",&n);
        while ( chainenum(n)==0){
            printf("INPUT_ERROR");
            scanf("%s",&n);
            
        }
        for(i=0;i<n;i++,printf("\n");){
            scanf("%s",&pi);
            while ( chainenum(pi)==0){
               printf("INPUT_ERROR");
               scanf("%s",&pi);
            }
            printf("\t");
            scanf("%s",&ri);
            while ( chainenum(ri)==0){
               printf("INPUT_ERROR");
               scanf("%s",&ri);
            }
        }
        x=0;
        s=0;
        while(x<3){
            while(s<atof(&b)){
                s+=atof(&pi)*x;
            }
            
        }
             
             
        
  
   
    
    
    return 0;
} 
     