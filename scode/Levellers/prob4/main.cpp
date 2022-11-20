#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){ int nb_lignes,i,j,f,k,l,e,b,n,s;
    char c[50][20];
    string ch;
   
    cin>> nb_lignes;

    
    for(i=0;i<nb_lignes+1;i++)
    {
      
        ch="";
        getline(cin,ch);
    
        e=ch.length();
        f=0;
        for(j=0;j<ch.length();j=j+2)
        {
            
           
           c[i][f]=(ch[j]);
           
           f++;
          
        }
        
    }}