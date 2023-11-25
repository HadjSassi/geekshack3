#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compile and get accepted.
 *      ____________
 *     /            \
 *    /  /\      /\  \
 *   /  /  \    /  \  \
 *   \                /
 *    \     \___/    /
 *     \____________/
 */






#define f(i,j,k) for(long long i=j;i<k;i++)
#define fb(i,j,k) for(long long i=j;i>=k;i--)
#define fs(i,j,k,p) for(long long i=j;i<k;i+=p)
#define fbs(i,j,k,p) for(long long i=j;i>=k;i-=p)
#define cond(a) if(a)cout<<"YES"<<endl;else cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define test int t;cin>>t;while(t--)
#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

ll PRO(ll a,ll b,ll MOD)
{
  return ((a%MOD)*(b%MOD)%MOD);
}
ll power(ll x, ll y, ll M)
{
  if (y == 0)
    return 1;
  ll p = power(x, y / 2, M) % M;
  p = (p * p) % M;
  return (y % 2 == 0) ? p : (x * p) % M;
}
bool isprime(ll n)
{

  for(ll i=2;i*i<=n;i++)
  {
    if(n%i==0)return false;
  }
  return true;
}


const ll mod = 1e9+7;
int add(int a, int b){
    return (a + b) % mod;
}
int sub(int a, int b){
    return (a - b + mod) % mod;
}
ll mul(int a, int b){
    return (((ll)a%mod) * ((ll)b%mod)) % mod;
}
ll mod_inv (ll a,ll modi)
{
    return power(a,modi-2,modi);
}

ll n1,n2;

struct node
{
    ll x;
    node()
    {
        x=-1e6;
    }
    node(ll i)
    {
        x=i;
    }
    void applyLazy(ll p,ll ns,ll ne)
    {
        x+=p;
    }
};

node merg (node i ,node j )
{
    return node(max(i.x,j.x));
}

struct segment_tree_lazy_propagation
{
    vector<node> tree;
    vector<int> lazy; // Lazy propagation array
    vector<bool> lazyFlag; // Lazy propagation flag array

    void clear ()
    {
        tree.clear();
        lazy.clear();
        lazyFlag.clear();
    }

    void init(int num, const vector<int>& pr)
    {
        n2=num;
        tree.assign(4 * n2, node());
        lazy.assign(4 * n2, 0);
        lazyFlag.assign(4 * n2, false);
        build(pr);
    }

    void build(const vector<int>& pr, int id = 0, int ns = 0, int ne = n2 - 1)
    {
        if (ns == ne) {
            tree[id] = node(pr[ns]);
            return;
        }

        int l = 2 * id + 1;
        int r = l + 1;
        int md = ns + (ne - ns) / 2;

        build(pr, l, ns, md);
        build(pr, r, md + 1, ne);

        tree[id] = merg(tree[l], tree[r]);
    }

    // Lazy propagation function
    void propagate(int id, int ns, int ne)
    {
        if (lazyFlag[id]) {
            tree[id].applyLazy(lazy[id],ns,ne);

            if (ns != ne) {
                lazy[2 * id + 1] += lazy[id];
                lazy[2 * id + 2] += lazy[id];
                lazyFlag[2 * id + 1] = lazyFlag[2 * id + 2] = true;
            }

            lazy[id] = 0;
            lazyFlag[id] = false;
        }
    }

    node query(int qs, int qe, int id = 0, int ns = 0, int ne = n2 - 1)
    {
        propagate(id, ns, ne);

        if (ns > qe || qs > ne) {
            return node(); // Infinity
        }

        if (qs <= ns && qe >= ne) {
            return tree[id];
        }

        int l = 2 * id + 1;
        int r = l + 1;
        int md = ns + (ne - ns) / 2;

        node ndl = query(qs, qe, l, ns, md);
        node ndr = query(qs, qe, r, md + 1, ne);

        return merg(ndl, ndr);
    }

    void upd(int qs, int qe, ll val, int id = 0, int ns = 0, int ne = n2 - 1)
    {
        propagate(id, ns, ne);

        if (ns > qe || qs > ne) {
            return;
        }

        if (qs <= ns && qe >= ne) {
            tree[id].applyLazy(val,ns,ns);

            if (ns != ne) {
                lazy[2 * id + 1] += val;
                lazy[2 * id + 2] += val;
                lazyFlag[2 * id + 1] = lazyFlag[2 * id + 2] = true;
            }

            return;
        }

        int l = 2 * id + 1;
        int r = l + 1;
        int md = ns + (ne - ns) / 2;

        upd(qs, qe, val, l, ns, md);
        upd(qs, qe, val, r, md + 1, ne);

        tree[id] = merg(tree[l], tree[r]);
    }

}sta;


ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}



vll prim(2e5+2,1);
void sieves(ll n ){
  prim[0]=0;
  f(i,2,n+1){
    if(prim[i]==0)continue;
    for(ll j = i;i*j<=n;j++){
      prim[i*j]=0;
    }
  }
}




int count(vector<int> &v, ll m, ll n)
{
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1 << n);
 
    for (counter = 1; counter < pow_set_size; counter++) {
        p = 1;
        for (j = 0; j < n; j++) {
            if (counter & (1 << j)) {
                p *= v[j];
            }
        }
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += (m / p);
    }
 
    return odd - even;
}





void solve()
{
  double l ,h, x ,y, vx,vy;
  int k;
  cin>>l>>h>>x>>y>>vx>>vy>>k;
  if(vx==0 && vy ==0){
      cout<<x<<' '<<y<<endl;
      return;
  }
  if(k==0){
      cout<<x<<' '<<y<<endl;
      return;
  }
  k--;
  if(vy==0){
      
      if(x==l){
          x = 0;
      }
      else x = l;
      if(k%2){
          x = l-x;
      }
      cout<<x<<' '<<y<<endl;
      return;
  }
  
  if(vx==0){
      if(y==h)y = 0;
      else y = h;
      if(k%2){
          y = h-y;
      }
      cout<<x<<' '<<y<<endl;
      return;
  }
  k++;
  if(y==h || x==l )k++;
  while(k--){
    double x1,y1;
    if(vy>=0)
    x1 = (h-y)*vx/vy+x;
    else x1 = -y*vx/vy+x;
    if(vx>=0)
    y1 = (l-x)*vy/vx+y;
    else {
      y1 = -x*vy/vx+y;
    }
    if(x1<l && x1>0){
      if(vy>=0){
        y = h;
      }
      else {
        y = 0;
      }
      vy = -vy;
      x=x1;
    }
    else if(y1<h && y1>0){
      if(vx>=0)x = l;
      else x = 0;
      vx = -vx;
      y = y1;
    }
    else {
      vx = -vx;
      vy = -vy;
      x = x1;y = y1;
    }
  }
  cout<<x<< ' '<<y<<endl;
}

int main()
{
  fastio();
  //std::cout << std::setprecision(11) << a << '\n';
  //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

  //test
  {
    solve();
  }
  return 0;
}

















 