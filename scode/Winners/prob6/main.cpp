#include<bits/stdc++.h>

using namespace std;
vector<char> Res;
vector<char> meetings;
vector<int> hours;
vector<int> profit;
 
int main()
{
	int W;
	cin >> W;
	int n;
	cin >> n;
	for (int i =0;i<n;i++){
		char c;
		int a,x;
		cin >> c >> a >> x;
		meetings.push_back(c);
		hours.push_back(a);
		profit.push_back(x);
	}
	int maxprofit = 0;
	int Resul = 0;
	for (int b=0;b < (1<<11) ; b++){
		int hourstotal = 0;
		int profittotal = 0;
		
		for (int i=0;i<11;i++){
			if (b & (1<<i)){
				hourstotal += hours[i];
				profittotal += profit[i];
			}
		}
		if (hourstotal <= W){
			if ( profittotal > maxprofit){
				Resul = b;
				maxprofit = profittotal;
			}
		}
	}
	int Resultat=0;
    for (int i=0;i<11;i++){
		if (Resul & (1<<i)){
			Res.push_back(meetings[i]);
			Resultat += profit[i];
		}
	}
	for (int i = 0;i<Res.size()-1;i++){
		cout << Res[i] << " ";
	}
	cout << Res[Res.size()-1] << "\n";
	cout << Resultat << endl;
    return 0;
}