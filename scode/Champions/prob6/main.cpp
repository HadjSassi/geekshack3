#include <bits/stdc++.h>
using namespace std;
int main (){
    string s,s1,s2;
    char c ;
    int n=0;
    cin>>n;
    cin >>c;
    for (int i=0;i<n;i++){
        cin>>s;
    }
    //cout<<s<<"\n";
   if (c=='E'){
       for (int i=n;i>0;i--){
           if (n%i==0){
                for (int j=0 ; j<i; j++){
                   s1[j]=s[i-j-1];
                   cout<<s1[j];
               }
               i--;
           }else{#include <bits/stdc++.h>
using namespace std;
int main (){
    string s,s1,s2;
    char c ;
    int n=0;
    cin>>n;
    cin >>c;
    for (int i=0;i<n;i++){
        cin>>s;
    }
    //cout<<s<<"\n";
   if (c=='E'){
       for (int i=n;i>0;i--){
           if (n%i==0){
                for (int j=0 ; j<i; j++){
                   s1[j]=s[i-j-1];
                   cout<<s1[j];
               }
               i--;
           }else{
              i--;
           }
         
          
       }
   }/*else if (c=='D'){
       for (int i=n;i>0;i--){
           if (n%i==0){
                for (int j=n;j>i;j--){
                   s1[j]=s[i-j-1];
                   cout<<s1[j];
               }
               i--;
           }else{
              i--;
           }
   }
   }
 //cout<<s;*/
    return 0;
}
              i--;
           }
         
          
       }
   }else if (c=='D'){
       for (int i=n;i>0;i--){
           if (n%i==0){
                for (int j=n;j>i;j--){
                   s1[j]=s[i-j-1];
                   cout<<s1[j];
               }
               i--;
           }else{
              i--;
           }
   }
   }
 //cout<<s;*/
    return 0;
}