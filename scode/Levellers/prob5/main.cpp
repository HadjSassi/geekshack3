

#include <iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <string>

typedef struct br1 {
    string  name;
    string value;
}br1;

string extract(int from, int to, string chaine, string sousChaine)
{
  int i=0, j=0;
  int length1 = chaine.length();
  
  for( i = from, j = 0; i <= to; i++, j++){
    sousChaine+=chaine[i];
  
  }  
  
  
  return (sousChaine);  
}

int position(string ch3, char c )
{
    int i;
    i=0;
    while(i<ch3.length()){
        
        if(ch3[i]==' ')return(i);
     i++;
        
    }
      return -1;
      
}









int main(){
    //printf("Bonjour Levellers !\nAllez, c'est à vous ! Bon courage ! ^_^");
    int nb_lignes;
    string ch;
    string ch1;
    string ch2;
    string ch3;
    string ch4;
    string ch5;
    string ch6;
    int i,j,s,l,k;
    s=1;
    br1 tab[50];
    cin>>nb_lignes;
   
   ch4="efgvj";
    if (nb_lignes<300){ 
    for(i=0;i<nb_lignes+1;i++)
    {ch=ch1=ch2=ch3="";
        getline(cin,ch);
     
        ch1=extract(3,ch.length()-1,ch,ch1);
        
        ch2=extract(0,position(ch1,' '),ch1,ch2);
        
        ch3=extract(position(ch1,' ')+1,ch1.length()-1,ch1,ch3);
        if(i==1){ch4=tab[1].name=ch2;}
        
      
      
     tab[i].name=ch2;
     tab[i].value=ch3;
     
   
           
       }
           
           
         
           
           
          for(l=2;l<nb_lignes+1;l++){
               if (tab[l].value[0]==tab[1].value[0]){
                   
                 if(tab[l].value.length()>tab[1].value.length())
                 ch5=tab[l].value+" : M";
               }
                  
          }
        cout<<ch5<<endl;
      for(k=2;k<nb_lignes+1;k++){
         
          if(tab[k].name[0]!='M' and tab[k].value[0]!=tab[1].value[0] and tab[k].value[0]!=ch5[0] )
          {cout<<tab[k].value<<" : U"<<"\n";}
          
          
          
      }
      
        for(k=1;k<nb_lignes+1;k++){
         
          if(tab[k].name[0]=='M' and tab[k].value[0]!='A')
          {cout<<tab[k].value<<"\n";}}
    }
      else cout<<"NO";
        
       return 0; 
       
        
    }
        