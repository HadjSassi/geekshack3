#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	if (cin >> n){
	}else{
		cout <<"NO" << endl;
		return 0;
	}
	string str;
	vector<string> v;
	cin.ignore();
	for (int i=0;i<n;i++){
		getline(cin,str);
		v.push_back(str);
		//cout << v[i] << endl;
	}
	vector<string> Main;
	vector<string> Branches;
	//Main.push_back("? ?");
	for (int i=0;i<n;i++){
		if ( v[i].substr(3,4) == "Main" ){
			if ( v[i].size()> 7 ){
				Main.push_back(v[i].substr(8, v[i].size()-8));
			}
		}
		else{
			int index = 0;
			int comp =0;
			for (int j=0;j<v[i].size();j++){

				if (v[i][j] == ' '){
					comp++;
				}
				if (comp==2){
					index = j+1;
					break;
				}
			}
			Branches.push_back(v[i].substr(index,v[i].size()-index));
		}
	}
	/*for (int i=0;i<Main.size();i++){
		cout << Main[i] << endl;
	}
	for (int i=0;i<Branches.size();i++){
		cout << Branches[i] << endl;
	}*/
	//sort(Main.begin(),Main.end());
	//sort(Branches.begin(),Main.end());
	if (Main.size() == 0){
		for (int i=0;i<Branches.size();i++){
			cout << Branches[i] << " : U" << endl;
		}
		return 0;
	}
	vector<set<string>> BranchesSet(Branches.size());
	vector<set<string>> MainSet(Main.size());
	for (int i=0;i<Branches.size();i++){
		int PrevInd=0;
		for (int j=0;j<Branches[i].size();j++){
			if (Branches[i][j]== ' '){
				BranchesSet[i].insert( Branches[i].substr(PrevInd,j-PrevInd) );
				PrevInd = j+1;
			}
			if (j==Branches[i].size()-1){
				BranchesSet[i].insert( Branches[i].substr(PrevInd,j-PrevInd+1));
			}
		}
	}
	for (int i=0;i<Main.size();i++){
		int PrevInd=0;
		for (int j=0;j<Main[i].size();j++){
			if (Main[i][j]== ' '){
				MainSet[i].insert( Main[i].substr(PrevInd,j-PrevInd) );
				PrevInd = j+1;
			}
			if (j==Main[i].size()-1){
				MainSet[i].insert( Main[i].substr(PrevInd,j-PrevInd+1));
			}
		}
	}
	/*for (int i=0;i<BranchesSet.size();i++){
		for (auto j : BranchesSet[i]){
			cout << j << " ";
		}
		cout << endl;
	}
	for (int i=0;i<MainSet.size();i++){
		for (auto j : MainSet[i]){
			cout << j << " ";
		}
		cout << endl;
	}*/
	int simi;
	for (int i=0;i<BranchesSet.size();i++){
		bool b = true;
		int com = 0;
		for (int j=0;j<MainSet.size();j++){
			simi = 0;
			for (auto k:BranchesSet[i] ){
				if ( MainSet[j].find(k) != MainSet[j].end()){
					simi++;
				}
			}
			//cout << simi << " " << BranchesSet[i].size() << " " << MainSet[j].size() << endl;
			if ( (simi == MainSet[j].size()) && (MainSet[j] == BranchesSet[i]) ){
				break;
			} else if ( ((simi < MainSet[j].size()) && (simi!=0)) || ( (simi!=0) && (simi == MainSet[j].size()) && (simi < BranchesSet[i].size()) ) ){
				//cout << "malla mawdhou3" << endl;
				Main[j] = Branches[i] + " : M";
				break;
			}
			else{
				com++;
			}
		}
		//cout << simi << endl;
		if (com == MainSet.size()){
			Main.push_back(Branches[i] + " : U");
		}
	}
	for (int i=0;i<Main.size();i++){
		if ( Main[i][Main[i].size()-1] == 'M')
			cout << Main[i] << endl;
	}
	for (int i=0;i<Main.size();i++){
		if (Main[i][Main[i].size()-1] == 'U')
			cout << Main[i] << endl;
	}
	for (int i=0;i<Main.size();i++){
		if ( ( Main[i][Main[i].size()-1] != 'U' ) && ( Main[i][Main[i].size()-1] != 'M') )
		cout << Main[i] << endl;
	}
	return 0;
}