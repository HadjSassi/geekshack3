#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
int arr[MAXN + 5];
struct segtree
{
#define lch (x << 1)
#define rch (x << 1 | 1)
    struct node
    {
        int l, r;
        int tg, cmn;
        int lmx, rmx, mx, ans, cnt;
    } t[4 * MAXN + 5];
    void pushup(int x)
    {
        t[x].mx = max(t[lch].mx, t[rch].mx);
        t[x].cmn = min(t[lch].cmn, t[rch].cmn);
        if (t[x].cmn == t[lch].cmn)
            t[x].lmx = t[lch].lmx;
        else
            t[x].lmx = max(t[lch].mx, t[rch].lmx);
        if (t[x].cmn == t[rch].cmn)
            t[x].rmx = t[rch].rmx;
        else
            t[x].rmx = max(t[rch].mx, t[lch].rmx);
        if (t[x].cmn != t[rch].cmn)
        {
            t[x].ans = t[lch].ans;
            t[x].cnt = t[lch].cnt + t[rch].r - t[rch].l + 1;
        }
        else if (t[x].cmn != t[lch].cmn)
        {
            t[x].ans = t[rch].ans;
            t[x].cnt = t[rch].cnt + t[lch].r - t[lch].l + 1;
        }
        else
        {
            t[x].ans = t[lch].ans + t[rch].ans;
            t[x].cnt = t[lch].cnt + t[rch].cnt;
            if (t[lch].rmx != -1 || t[rch].lmx != -1)
                t[x].ans += max(t[lch].rmx, t[rch].lmx), t[x].cnt++;
        }
    }
    void pushdown(int x)
    {
        if (t[x].tg)
        {
            t[lch].tg += t[x].tg, t[rch].tg += t[x].tg;
            t[lch].cmn += t[x].tg, t[rch].cmn += t[x].tg;
            t[x].tg = 0;
        }
    }
    void build(int x, int l, int r)
    {
        t[x].l = l, t[x].r = r, t[x].tg = 0, t[x].ans = 0;
        if (l == r)
        {
            t[x].cmn = 0, t[x].lmx = t[x].rmx = -1, t[x].mx = max(arr[l], arr[l + 1]);
            return;
        }
        int mid = (l + r) >> 1;
        build(lch, l, mid), build(rch, mid + 1, r);
        pushup(x);
    }
    void update(int x, int p)
    {
        if (t[x].l > p || t[x].r < p)
            return;
        if (t[x].l == t[x].r)
        {
            t[x].mx = max(arr[p], arr[p + 1]);
            return;
        }
        pushdown(x);
        update(lch, p);
        update(rch, p);
        pushup(x);
    }
    void modify(int x, int l, int r, int d)
    {
        if (l <= t[x].l && t[x].r <= r)
        {
            t[x].tg += d, t[x].cmn += d;
            return;
        }
        if (l > t[x].r || r < t[x].l)
            return;
        pushdown(x);
        modify(lch, l, r, d);
        modify(rch, l, r, d);
        pushup(x);
    }
} T;
set<int> st[MAXN + 5];
int a[MAXN + 5], n;
void update(int p) { T.update(1, p - 1), T.update(1, p); }
void remove(int x)
{
    int l = *st[a[x]].begin(), r = *st[a[x]].rbegin();
    T.modify(1, l, r - 1, -1), arr[l] = 0, update(l);
    st[a[x]].erase(x);
    if (!st[a[x]].empty())
    {
        int l = *st[a[x]].begin(), r = *st[a[x]].rbegin();
        T.modify(1, l, r - 1, 1), arr[l] = st[a[x]].size(), update(l);
    }
}
void add(int x)
{
    if (!st[a[x]].empty())
    {
        int l = *st[a[x]].begin(), r = *st[a[x]].rbegin();
        T.modify(1, l, r - 1, -1), arr[l] = 0, update(l);
    }
    st[a[x]].insert(x);
    int l = *st[a[x]].begin(), r = *st[a[x]].rbegin();
    T.modify(1, l, r - 1, 1), arr[l] = st[a[x]].size(), update(l);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    T.build(1, 0, n);
    for (int i = 1; i <= n; i++)
        add(i);
    printf("%d\n", T.t[1].cnt - T.t[1].ans);

}