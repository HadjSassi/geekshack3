#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() { int nb=0,i,j,K=0,L=0;char*s [1000];char ch1,ch2;
do{printf("input a string so i can give you the number of delicious substrings:\n");
scanf("%1000s",s);}
for (i=0;i<=1000;i++)
{
        if((*s[i]=="c")&&(*s[i++]=="h")&&(*s[i+=2]=="a")&&(*s[i+=3]=="k"))
              {
                ch1="chak";
                 K=i;}
        for(j=0;j<=1000;j++)
        {if ((*s[j]=="c")&&(*s[j++]=="h")&&(*s[j+=2]=="o")&&(*s[j+=3]=="u")&&(*s[j+=4]=="k")&&(*s[j+=5]=="a"))
              {ch2="chouka";
              L=j;}
          }}
if(L>K) nb++;
printf("this is the number of your delicious substrings: %d ",nb);

	return 0;
 }