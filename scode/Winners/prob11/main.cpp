#include <bits/stdc++.h>

using namespace std;

int main(){
	bool b = true;
	vector<string> res;
	//freopen("input.txt","r",stdin);
	string str;
	getline(cin,str);
	vector<string> input;
	vector<int> inputint;
	int PrevInd=0;
	for(int i=0;i<str.size();i++){
		if ( str[i]==' ' ){
			input.push_back( str.substr(PrevInd,i-PrevInd) );
			PrevInd = i+1;
		}
		if (i == str.size() - 1 ){
			input.push_back(str.substr(PrevInd,i-PrevInd+1));
		}
		
	}
	for(int i=0;i<input.size();i++){
		bool b2 = true;
		for (int j=0;j<input[i].size();j++){
			if (!isdigit(input[i][j])){
				b2 = false;
				b=false;
			}
		}
		if (b2){
			inputint.push_back(stoi(input[i]));
		}
	}
	if (!b){
		cout << "NOT_CLEAR" << endl;
		return 0;
	}
	for (int i=0;i<inputint.size();i++){
		bitset<4> bs(inputint[i]);
		for (int i=3;i>=0;i--){
			if (bs[i]){
				if (i==0){
					res.push_back("take_position");
				}else if (i==1){
					res.push_back("run");
				}else if (i==2){
					res.push_back("need_backup");
				}else if (i==3){
					res.push_back("declare_your_position");
				}
			}
		}
	}
	for (int i=0;i<res.size()-1;i++){
			cout << res[i] << " ";
		}
	cout << res[res.size()-1] << endl;
	return 0;
}  