#include<stdio.h>
using namespace std;
#include<string>
#include<iostream>

struct meet{
	string nom;
	int dure,profit;
	bool bol=true;
};
void remplir(meet m[10],int v){
	for(int i=0;i<v;i++){
		cout<<"donner le nom, le dure et le profit:\n";
		cin>>m[i].nom;
		cin>>m[i].dure;
		cin>>m[i].profit;
	}
}
meet maxi(meet t[],int n){
	meet me;
	int m=t[0].profit;string nm=t[0].nom;
	for(int i=1;i<n;i++){
		if(m<t[i].profit){
			m=t[i].profit;
			nm=t[i].nom;
		}
	}
	me.profit=m;
	me.nom=nm;
	return me;
}
void compter(meet A[10],int H){
	int n=A[0].dure,v=A[0].profit,i=1,k=0,x=0;
	meet t[10];
		while(x<3){
			while(i<=3){	
				if(n+A[i].dure<H ){    
					n+=A[i].dure;
					v+=A[i].profit;
					t[k].profit=v;
					t[k].nom=A[x].nom+A[i].nom;
					k++;
					A[i].bol=false;
					i++;
					//cout<<"************";
					//cout<<" n= "<<n<<" v= "<<v<<"\n i= "<<i<<" t====>"<<t[k-1].profit<<endl;	
				}else if(n+A[i].dure>H){
					i++;
					//cout<<"on peut pas l'ajouter car elle depaase ==>> i= "<<i<<endl;
				}else if(n+A[i].dure==H && A[i].bol==true){
					n+=A[i].dure;
					v+=A[i].profit;
					t[k].profit=v;
					t[k].nom=A[x].nom+A[i].nom;
					k++;
					//cout<<"\n i="<<i<<" n= "<<n<<" v= "<<v<<" t[k]= "<<t[k-1].profit;	
					n=A[x].dure;
					v=A[x].profit;
					i++;	
					//cout<<"/// n= "<<n<<" v= "<<v<<endl;
				}
			}
			x++;
			i=x+1;
			n=A[i-1].dure;
			v=A[i-1].profit;
			//cout<<" hors boucle > x="<<x<<" i= "<<i<<" n="<<n<<" v="<<v<<endl;		
		}
	
	/*for(int i=0;i<k;i++){
		cout<<" \nt= "<< t[i].nom<<t[i].profit<<endl;
	}*/
	cout<<maxi(t,k).nom<<" "<<maxi(t,k).profit;
}

int main(){

	meet A[10];	
	int dur,per;
	cout<<" donner ton duree maximale ";
	cin>>dur;
		cout<<" donner le nombre des personnes ";
	cin>>per;
	remplir(A,per);
	compter(A,dur);
	return 0;
}











	 