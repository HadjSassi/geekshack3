//
// Created by Ahmed Amamou on 17/11/2023.
//
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stdout, ##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
//#define int long long
inline int read(){int x=0,f=1;char ch=getchar(); while(ch<'0'||
                                                       ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
#define Z(x) (x)*(x)
#define pb push_back
#define fi first
#define se second
//srand(time(0));
#define N 5000010
//#define M
//#define mo
struct node {
    int l, r, id, op;
}a[N];
int n, m, i, j, k, T;
struct cmp {
    bool operator () (int x, int y) const {
        if(x<=n && y>n) return 1;
        if(y<=n && x>n) return 0;
        if(x<=n && y<=n) return x>y;
        if(x>n && y>n) return x>y;
    }
};
priority_queue<int, vector<int>, cmp >q;
int c[N], b[N], tot;
vector<int>G[N];

void cun(int x, int y) {
//	debug("%d -> %d\n", x, y);
    G[x].pb(y); ++c[y];
}

void solve(int l, int r) {
    int i;
    if(l==r) return ;
    int mid=(l+r)>>1;
    solve(l, mid); solve(mid+1, r);
    for(i=l; i<=mid; ++i) a[i].op=0;
    for(i=mid+1; i<=r; ++i) a[i].op=1;
    sort(a+l, a+r+1, [&] (node x, node y) { return x.r<y.r; });
    for(i=l; i<=r; ++i) b[i]=++tot;
    for(i=l; i<=r-1; ++i) cun(b[i], b[i]+1);
    for(i=l; i<=r; ++i)
        if(a[i].op==0) cun(a[i].id, b[i]);
        else cun(b[i], a[i].id);
}

signed main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
	  freopen("out.txt", "w", stdout);
#endif
//	T=read();
//	while(T--) {
//
//	}
    n=read(); tot=n;
    for(i=1; i<=n; ++i) a[i].id=i;
    for(i=1; i<=2*n; ++i) {
        k=read();
        if(!a[k].l) a[k].l=i; else a[k].r=i;
    }
    sort(a+1, a+n+1, [] (node x, node y) { return x.l<y.l; });
    solve(1, n);
    for(i=1; i<=tot; ++i) if(!c[i]) q.push(i);
    while(!q.empty()) {
        auto u=q.top(); q.pop();
//		debug("# %d\n",  u);
        if(u<=n) printf("%d %d ", u, u);
        for(auto v : G[u])
            if(--c[v]==0) q.push(v);
    }
    return 0;
}
