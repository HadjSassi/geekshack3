#include <iostream>
using namespace std;
int test(string s) {
    int i = 0, j = s.length()-1,k,ans=0;
  int max=0;
    while(i<j){
      max++;
  
        if(s[i]==s[j]){
            i++;j--;
        }else{
            k = j;
            while(k>=i && s[k] != s[i]){
                k--;
            }
            if(k==i){
                ans++;
                swap(s[i],s[i+1]);
            }else{
                while(k<j){
                    swap(s[k],s[k+1]);
                    k++;
                    ans++;
                }
                i++;j--;
            }
        }
      if(max>255){ return -1;}
    }
    return ans;
}
int main(){
  string ch;
  cin >> ch;
  int s=test(ch);
  cout<<s;
}