#include<bits/stdc++.h>
using namespace std;
struct Q{
	int x;
	int y;
}u,v;
queue<Q>q;
char s[1005][1005];
int dp[1005][1005],n,m,k,i,j,a,b,c,d;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main(){
	cin>>n>>m>>k;
		cin>>a>>b>>c>>d;
	for(i=1;i<=n;i++) cin>>s[i]+1;
	memset(dp,10000,sizeof(dp));
	dp[a][b]=0;
	v.x=a;v.y=b;
	q.push(v);
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(u.x==c&&u.y==d){
			cout<<dp[u.x][u.y];
			return 0;
		}
		for(i=0;i<4;i++){
			for(j=1;j<=k;j++){
				v.x=u.x+dx[i]*j;
				v.y=u.y+dy[i]*j;
				if(s[v.x][v.y]!='.'||dp[v.x][v.y]<=dp[u.x][u.y]) break;
				if(s[v.x][v.y]=='.'&&dp[v.x][v.y]>dp[u.x][u.y]+1){
					dp[v.x][v.y]=dp[u.x][u.y]+1;
					q.push(v);
				}
			}
		}
	}
	cout<<-1;
	return 0;
}