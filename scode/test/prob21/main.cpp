#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define boo(i) bitset<i>
#define ri register int
#define rll register long long
#define mem(x) memset(x,0,sizeof(x))
#define max_(i,j) (i<j?j:i)
#define min_(i,j) (i<j?i:j)
#define abs_(x) (x>0?x:(-x))
using namespace std;
int n,len,rt; 
int a[1000001];
vector<int>ed[6400001];
int in[6400001],rep[1000001];
void add_l(int x,int y){
	if(x==0||y==0){
		return;
	}
	ed[x].push_back(y);
	in[y]++;
}
pair<int,int>p[1000001]; 
struct SEG{
	int l,r;
}tr[6400001];
void zadd(int l,int r,int ll,int rr,int y,int &pos){
	len++;pos=len;
	tr[pos]=tr[y];
	if(l==r){
		add_l(pos,rr);
		return;
	}
	ri mid=(l+r)>>1;
	if(ll<=mid){
		zadd(l,mid,ll,rr,tr[y].l,tr[pos].l);
	}else{
		zadd(mid+1,r,ll,rr,tr[y].r,tr[pos].r);
	}
	add_l(pos,tr[pos].l);add_l(pos,tr[pos].r);
}
void upd(int l,int r,int st,int en,int pos,int x){
	if(x==0){
		return;
	}
	if(st<=l&&en>=r){
		add_l(pos,x);
		return;
	}
	ri mid=(l+r)>>1;
	if(st<=mid){
		upd(l,mid,st,en,pos,tr[x].l);
	}
	if(en>mid){
		upd(mid+1,r,st,en,pos,tr[x].r);
	}
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
vector<int>ans;
void tp(){
	for(int i=1;i<=len;i++){
		if(!in[i]){
			if(i<=n){
				q.push(make_pair(i,i));
			}else{
				q.push(make_pair(0,i));
			}
		}
	}
	int x;
	while(!q.empty()){
		pair<int,int>t=q.top();q.pop();
		x=t.second;
		if(x<=n){
			ans.push_back(x);ans.push_back(x);
		}
		for(int i=0;i<ed[x].size();i++){
			in[ed[x][i]]--;
			if(in[ed[x][i]]==0){
				if(ed[x][i]<=n){
					q.push(make_pair(ed[x][i],ed[x][i]));
				}else{
					q.push(make_pair(0,ed[x][i]));
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	len=n;
	for(int i=1;i<=(2*n);i++){
		scanf("%d",&a[i]);
		if(!p[a[i]].first){
			p[a[i]].first=i;
		}else{
			p[a[i]].second=i;
		}
	}
	for(int i=1;i<=n;i++){
		rep[p[i].first]=p[i].second;
	}
	for(int i=n*2;i>=1;i--){
		if(!rep[i]){
			continue;
		}
		upd(1,n*2,rep[i],n*2,a[i],rt);
		zadd(1,n*2,rep[i],a[i],rt,rt);
	}
	tp();
	int po=0;
	for(int i=0;i<2*n-1;i++){
		printf("%d ",ans[i]);
		po=i;
	}
	printf("%d",ans[po]);
}
             