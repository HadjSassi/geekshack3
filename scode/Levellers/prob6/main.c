#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bussinessman{
    char profitable_bussiness;
    int nb_h;
    int gain;
    
}bussinessman;

int extract(int from, int to, char *chaine, char *sousChaine)
{
  int i=0, j=0;
  int length = strlen(chaine);
  
  if( from > length || from < 0 ){
    return 1;
  }
  if( to > length ){
    return 1;
  }  
  for( i = from, j = 0; i <= to; i++, j++){
    sousChaine[j] = chaine[i];
  }  
  return 0;  
}

int position_1ere_occurence_espace(char * ch, char c )
{
    int i;
    for(i=0;i<strlen(ch);i++)
    {
        if(ch[i]==c)
            return i;
        else
        return -1;
        
    }
}

int position_2eme_occurence_espace(char *ch,char c)
{
	int i;
    for(i=position_1ere_occurence_espace(ch,' ');i<strlen(ch);i++)
    {
        if(ch[i]==c)
            return i;
        else
            return -1;
    }   
}


int main(){
    int h,p,i,j,s,g,max,x;char* chaine;
    char  ch[100];
    char ch1[10];
    char ch2[10];
    
    bussinessman tab[100];
    scanf("%d",&h); //nb hours
    scanf("%d",&p); // profitable bussiness number
    for(i=0;i<p;i++)
    {
        fgets(ch,100,stdin);
        tab[i].profitable_bussiness=ch[0];/* strncpy(tab[i].profitable_bussiness,ch[i],1);*/
        extract(1,position_1ere_occurence_espace(ch,' '),ch,ch1);
        puts(ch1);
        tab[i].nb_h=atoi(ch1);
        extract(position_2eme_occurence_espace(ch,' '),strlen(ch)-1,ch,ch2);
        puts(ch2);
		tab[i].gain=atoi(ch2);
		
    }
    //Affichage 
    /*for(j=0;j<p;j++)
    {
    	printf("profitable %c ",tab[j].profitable_bussiness);
    	printf("nb_h %d ",tab[j].nb_h);
    	printf("gain %d ",tab[j].gain);
	}*/
    /*for (j=0;j<p;j++){
        max=0;
        g=atoi(tab[j].gain);
        s=atoi(tab[j].nb_h);
        strcat(chaine,tab[j].profitable_bussiness);
        x=j+1;
        while(x<n){
            if(s+atoi(tab[x].nb_h)<atoi(h)){
                if(max<g+atoi(tab[x].gain)){max=g+atoi(tab[x].gain;strcat(chaine,tab[x].profitable_bussiness)}
                
                
                
            }
            
          x++;  
            
        }
             
    }
    printf("%s\n",chaine);
    printf("%d",max);*/
    
    return 0;
} 