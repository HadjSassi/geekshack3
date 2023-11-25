#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,w,a[N*2],cnt[N],vis[N*2];
long long ans;
struct star{int val,id;};
bool operator <(const star&a,const star&b){return a.val>b.val;}
priority_queue<star> Q1,Q2;
void clear(int type){
    if(type==1)while(!Q1.empty()&&vis[Q1.top().id])Q1.pop();
    if(type==2)while(!Q2.empty()&&vis[Q2.top().id])Q2.pop();
}
int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++){
        scanf("%d%d",a+i,a+i+n);
        Q1.push({a[i],i});
        Q2.push({a[i+n],i});
        a[i+n]-=a[i];
    }
    while(w--){
        clear(1);clear(2);
        int i=Q1.top().id;Q1.pop();clear(1);
        if(w&&Q2.size()&&a[i]+Q1.top().val>=Q2.top().val)
            Q1.push({a[i],i}),i=Q2.top().id,Q2.pop();
        if(i<=n)Q1.push({a[i+n],i+n});
        ans+=a[i];cnt[(i>n?i-n:i)]++;vis[i]=1;
    }
    printf("%lld\n",ans);
    // for(int i=1;i<=n;i++)printf("%d",cnt[i]);
    return 0;
} 