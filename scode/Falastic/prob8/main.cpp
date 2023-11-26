/*#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
    int  ind2,ind1,calc2,calc1,n,a,k,sum1,sum2;
    int maxi1=0,maxi2=0;
    cin>>n;
    vector<deque<int>> vect;
  //  vector<deque<int>>v;
    auto it=vect.begin();
    while(n--){
    deque<int> d;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a;
        d.push_front(a);
    }

    vect.insert(it,d);
    it++;
    for(int i=0;i<vect.size();i++){
    if(!(vect[i]).empty()){
    	calc1=(vect[i]).front();
	    if (calc1>maxi1){
	        maxi1=calc1;
	        ind1=i;
	    }
	    calc2=(vect[i]).back();
	    if(calc2>maxi2){
	        maxi2=calc2;
	        ind2=i;
	    	}
	    }
	}
sum1=sum1+vect[ind1].front();
vect[ind1].pop_front();
sum2=sum2+vect[ind1].back();
vect[ind2].pop_back();

}
cout<<sum1<<sum2;
return 0;
} */
#include<cmath>
#include<deque>
#include<iostream>
using namespace std;
int main(){
    int n,maxi1=0,maxi2=0,a;
    deque<int> dq1,dq2;
    cin>>n;
    cin>>a;
     for (int j=0;j<a;j++){
            dq1.push_front(a);
        }
    cin>>a;
     for (int j=0;j<a;j++){
            dq1.push_front(a);
    }
    maxi1=maxi1+dq1.front();
    dq1.pop_front();
    maxi2=maxi2+dq2.back();
    dq2.pop_back();
    maxi1=maxi1+dq2.front();
    dq2.pop_front();
    cout<<maxi1<<maxi2;
return 0;}
