#include<stdio.h>
int findbg(ch)
{int a,i;
a=0;i=0;
 while( a=0)
 { if((ch[i]=="(")||(ch[i]=="{") || (ch[i]=="[") || (ch[i]=='"') || (ch[i]=="'" ))
      return(i)
   else {return(101);}

void supp(ch,j,i)
{ int k;
 
  for(k=j;j<i;j++)
    {ch[k]=ch[k+(i-j+1)];
   }

int main()
{ char s[100];
  int j,l,i
 gets(s);
 j=0;
 l=strlen(ch) ;
 while(j<l)
 {if( findbg(ch)==101)
    print("SYNTAXE_ERROR");
 else {i=findbg(ch); supp(ch,j,i);l-=(i-j+1);}}
 puts(ch);
return 0;
getch();
}