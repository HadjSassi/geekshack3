#include<stdio.h>
#include<conio.h>
int main(){
    ch=getch();
    ch1="";
    i=0;
    while (ch[i]!='\o'){
        if ch[i] in ["{","'",'"',"(","[","`"]{
            switch ch[i]{
            case "{":do{ch1=ch1+ch[i];i+=1;}while(ch[i]!="}");break;
            case "'":do{ch1=ch1+ch[i];i+=1;}while(ch[i]!="'");break;
                
            case '"':do{ch1=ch1+ch[i];i+=1;}while(ch[i]!='"');break;
               
            case "(":do{ch1=ch1+ch[i];i+=1;}while(ch[i]!=")");break;
                
            case "[":do{ch1=ch1+ch[i];i+=1;}while(ch[i]!="]");break;
                
            case "`":do{ch1=ch1+ch[i];i+=1;}while(ch[i]!="`");break;}}
    printf (ch1)
    return 0;
} 