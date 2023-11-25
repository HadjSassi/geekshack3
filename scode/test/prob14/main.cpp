#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int maxn=2e5+10;
int vis[30],ok[maxn],tr[maxn];
int n;

deque<int>pos[30];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

int lowbit(int x){return x&(-x);}

void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=y;
    return ;
}

int query(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))ret+=tr[i];
    return ret;
}

signed main()
{
    string s;
    cin>>s;
    n=s.size();s='%'+s;
    for(int i=1;i<=n;i++)
    {
        vis[s[i]-'a']++;
        pos[s[i]-'a'].push_back(i);
    }
    int cnt=0;
    char now='%';
    for(int i=0;i<26;i++)
    {
        if(vis[i]&1)cnt++,now=i+'a';
    }
    if(cnt>1){cout<<-1<<'\n';exit(0);}
    int st=1,ed=n;
    for(int i=1;i<=n;i++)
    {
        if(ok[i])continue;
        int c=s[i]-'a';
        if(s[i]==now&&pos[c].size()==1)
        {
            ok[i]=n/2+1;
            continue;
        }
        ok[i]=st;
        pos[c].pop_front();
        ok[pos[c].back()]=ed;
        pos[c].pop_back();
        st++;ed--;
//		cout<<st<<" "<<ed<<'\n';
    }
    int ans=0;
    for(int i=n;i>0;i--)
    {
        ans+=query(ok[i]);
        add(ok[i],1);
    }
    cout<<ans<<'\n';
    return 0;
}
