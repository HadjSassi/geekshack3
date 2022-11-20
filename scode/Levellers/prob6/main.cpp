#include <iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sstream>

typedef struct bussinessman{
    string profitable_bussiness;
    int nb_h;
    int gain;
   
}bussinessman;

typedef struct profits{
    string profs;
    int gains;
   
}profits;


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

    int nb_lignes;
    string ch;
    string ch1;
    string ch2;
    string ch3;
    int h,p,i,j,s,g,max,x;
 
    bussinessman tab[100];
    scanf("%d",&h); //nb hours
    scanf("%d",&p); // profitable bussiness number
    
    getline(cin,ch);
    for(i=0;i<p;i++)
    {ch=ch1=ch2=ch3="";
        tab[i].profitable_bussiness="";
        getline(cin,ch);
        tab[i].profitable_bussiness+=ch[0];
        ch1=extract(2,ch.length()-1,ch,ch1);
        ch2=extract(0,position(ch1,' '),ch1,ch2);
        ch3=extract(position(ch1,' ')+1,ch1.length()-1,ch1,ch3);
    stringstream container(ch2);
    int x;
    container >> tab[i].nb_h;
   
    
    stringstream container1(ch3);
    int y;
    container1 >> tab[i].gain;
 
    
}

int k=0;

int nbgain=0;
int nbh=0;
int f=0;


profits pr[20];

while(k<p){
    string profs= "";
     nbh=tab[k].nb_h;
     nbgain=tab[k].gain;
     profs= tab[k].profitable_bussiness;
     
    f=k+1;

   while(nbh<=h && f<p){
      cout<<nbh<<endl;
       
      if(nbh+tab[f].nb_h<=h)
      {
       nbh=nbh+tab[f].nb_h;
       nbgain=nbh+tab[f].gain;
       profs=profs+(" "+tab[f].profitable_bussiness);
       
       f++;}
       else {f++;}
   }
    cout<<profs;k++;
    pr[k].profs=profs;
    pr[k].gains=nbgain;
    cout<<nbgain;
    break;
    
   
    
    
    
}
    
   
    
  /* for(int k=0;k<j;k++){
        if(pr[k].gains>pr[max].gains) max=k;
    }
    cout<<pr[0].profs<<endl;
    cout<<pr[0].gains<<endl;*/
}
       

 
             