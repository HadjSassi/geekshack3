#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

struct node {
  node *p, *c[2];
  ll f, w, s, v, t, k, a, b;
  node(){}
  node(int _w) : p(), c(), f() {
    w = _w;
    s = _w;
    v = 0;
    t = 0;
    k = INF;
    a = 0;
    b = 0;
  }
};

ll size(node *n){ return n != NULL ? n -> s : 0; }
ll val(node *n){ return n != NULL ? n -> v : 0; }
ll sum(node *n){ return n != NULL ? n -> t : 0; }

void push(node *n){
  if(n == NULL) return;
  if(n -> f){
    if(n -> c[0]){
      n -> c[0] -> f ^= 1;
      n -> c[0] -> a += (n -> c[0] -> s + 1) * n -> c[0] -> b;
      n -> c[0] -> b = -n -> c[0] -> b;
    }
    if(n -> c[1]){
      n -> c[1] -> f ^= 1;
      n -> c[1] -> a += (n -> c[1] -> s + 1) * n -> c[1] -> b;
      n -> c[1] -> b = -n -> c[1] -> b;
    }
    swap(n -> c[0], n -> c[1]);
    n -> f = 0;
  }
  if(n -> k != INF){
    if(n -> w) n -> v = n -> k;
    n -> t = n -> s * n -> k;
    if(n -> c[0]){
      n -> c[0] -> k = n -> k;
      n -> c[0] -> a = n -> c[0] -> b = 0;
    }
    if(n -> c[1]){
      n -> c[1] -> k = n -> k;
      n -> c[1] -> a = n -> c[1] -> b = 0;
    }
    n -> k = INF;
  }
  if(n -> w){
    n -> v += n -> a;
    n -> v += (size(n -> c[0]) + n -> w) * n -> b;
  }
  if(n -> c[0]){
    n -> c[0] -> a += n -> a;
    n -> c[0] -> b += n -> b;
  }
  if(n -> c[1]){
    n -> c[1] -> a += n -> a + (size(n -> c[0]) + n -> w) * n -> b;
    n -> c[1] -> b += n -> b;
  }
  n -> t += n -> s * n -> a;
  n -> t += n -> s * (n -> s + 1) / 2 * n -> b;
  n -> a = n -> b = 0;
}

void pull(node *n){
  if(n == NULL) return;
  push(n), push(n -> c[0]), push(n -> c[1]);
  n -> s = n -> w + size(n -> c[0]) + size(n -> c[1]);
  n -> t = n -> v + sum(n -> c[0]) + sum(n -> c[1]);
}

int dir(node *n){
  return n == n -> p -> c[1];
}

bool is_root(node *n){
  return n -> p == NULL || n != n -> p -> c[dir(n)];
}

void connect(node *n, node *p, int d){
  if(n != NULL) n -> p = p;
  if(p != NULL) p -> c[d] = n;
}

void rotate(node *n){
  bool d = dir(n);
  node *p = n -> p;
  connect(n -> c[!d], p, d);
  if(is_root(p)) n -> p = p -> p;
  else connect(n, p -> p, dir(p));
  connect(p, n, !d);
  pull(p), pull(n);
}

void splay(node *n){
  while(!is_root(n)){
    node *p = n -> p;
    if(!is_root(p)) push(p -> p);
    push(p), push(n);
    if(!is_root(p)){
      bool b = dir(n) ^ dir(p);
      rotate(b ? n : p);
    }
    rotate(n);
  }
  push(n);
}

void expose(node *n){
  node *l = NULL, *m = n;
  for( ; m != NULL; m = m -> p){
    splay(m);
    m -> c[1] = l;
    pull(m);
    l = m;
  }
  splay(n);
}

void evert(node *n){
  expose(n);
  n -> f ^= 1;
}

void link(node *m, node *n){
  evert(m), expose(n);
  m -> p = n;
}

ll path_len(node *m, node *n){
  evert(m), expose(n);
  return size(n);
}

ll path_sum(node *m, node *n){
  evert(m), expose(n);
  return sum(n);
}

void path_set(node *m, node *n, ll v){
  evert(m), expose(n);
  n -> k = v;
  n -> a = n -> b = 0;
}

void path_inc(node *m, node *n, ll v){
  evert(m), expose(n);
  n -> b += v;
}

const ll MOD = 1000000007;
const int MAXN = 10000005;

node buf[2 * MAXN], *ptr = buf;

node* new_node(int w){
  *ptr = node(w);
  return ptr++;
}

int T, N, Q;
node *V[MAXN];

int main(){
  scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i++){
      V[i] = new_node(0);
    }
    for(int i = 1; i < N; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      node *e = new_node(1);
      link(V[a], e);
      link(V[b], e);
    }
    ll time = 0, res = 0;
    for(int i = 1; i <= Q; i++){
      int a, b, x;
      scanf("%d%d%d", &a, &b, &x);
      ll len = path_len(V[a], V[b]);
      ll rem = time * len - path_sum(V[a], V[b]);
      if(x == 0){
        path_set(V[a], V[b], time);
      } else {
        path_set(V[a], V[b], time - 1);
        path_inc(V[a], V[b], 1);
        time = (time + len) % MOD;
        rem += len * (len - 1) / 2;
      }
      rem = (rem % MOD + MOD) % MOD;
      res = (res + i * rem) % MOD;
    }
    printf("%lld\n", res);
    ptr = buf;
  }
}