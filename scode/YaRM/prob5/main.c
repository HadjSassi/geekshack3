#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Bonjour YaRM !\nAllez, c'est à vous ! Bon courage ! ^_^");
    char chaine[100]; char chaine2[100];
    scanf("%s" , &chaine);
    int j =0 ; int nb =0; 
    for (int i=0 ; i<chaine.length() ; i++){
        
        if (chaine[i] == "\n"){
            strncpy(chaine2, chaine + 0, i - j);
            j=i+1;
            printf("la chaine est " + chaine2);
            if (nb ==1){ int n = chaine2.atoi() ; }
            else {
                if (strstr(chaine2, "main") != NULL) {
                      char chaineRet = strncpy(chaine2 , 8 , length(chaine2)) ; 
                      chaineRet+ "\n" ; 
                      printf(chaineRet);
                                                      }
            }
        }
        
    }
    return 0;
} 