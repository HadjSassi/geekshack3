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
        
    }

    
       /* for(k=1;k<nb_lignes+1;k=k+1){
            for(l=0;l<4;l=l+1){
              
              
              cout<<c[k][l]<<" ";}
            
            cout<<endl;
        }*/s=0;
         for(b=1;b<nb_lignes+1;b=b+1){
            for(n=0;n<e/2+1;n=n+1){
              if (c[b][n]=='1')
                 {if (c[b][n+1]=='4' and c[b-1][n+1]=='3' and c[b-1][n]=='2') {s=s+1;};
              if (c[b][n+1]=='2' and c[b-1][n+1]=='3' and c[b-1][n]=='4') {s=s+1;};
              if (c[b][n+1]=='2' and c[b+1][n+1]=='3' and c[b+1][n]=='4') {s=s+1;};
              if (c[b][n+1]=='4' and c[b+1][n+1]=='3' and c[b+1][n]=='2') {s=s+1;};
             if (c[b+1][n]=='2' and c[b+1][n-1]=='3' and c[b][n-1]=='4') {s=s+1;};
             if (c[b+1][n]=='4' and c[b+1][n-1]=='3' and c[b][n-1]=='2') {s=s+1;};
             if (c[b][n-1]=='2' and c[b-1][n-1]=='3' and c[b-1][n]=='4') {s=s+1;};
              if (c[b][n-1]=='4' and c[b-1][n-1]=='3' and c[b-1][n]=='2') {s=s+1;};       
                 }
             
        }
        cout<<s<<endl;
   return 0;
   
   
         }
}    
 