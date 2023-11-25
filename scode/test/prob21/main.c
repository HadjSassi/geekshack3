#include <stdio.h>
#include <string.h>

#define N	200000
#define N_	(1 << 19)	/* N_ = pow2(ceil(log2(N * 2 + 1))) */
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int aa[N * 2], ii[N], jj[N], n;

int st[N_ * 2], n_;

void pul(int i) {
	st[i] = min(st[i << 1 | 0], st[i << 1 | 1]);
}

void build() {
	int i, a;

	n_ = 1;
	while (n_ <= n * 2)
		n_ <<= 1;
	memset(st, 0x3f, n_ * 2 * sizeof *st);
	for (a = 0; a < n; a++)
		st[n_ + ii[a]] = jj[a];
	for (i = n_ - 1; i > 0; i--)
		pul(i);
}

void update(int i) {
	i += n_;
	st[i] = INF;
	while (i > 1)
		pul(i >>= 1);
}

int query(int r) {
	int l = 0, x = INF;

	for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1)
		if ((r & 1) == 0)
			x = min(x, st[r--]);
	return x;
}

int find(int x) {
	int i;

	if (st[1] >= x)
		return -1;
	i = 1;
	while (i < n_)
		i = st[i << 1 | 0] < x ? i << 1 | 0 : i << 1 | 1;
	return i - n_;
}

int iq[N + 1], pq[N], cnt;

int lt(int i, int j) { return i < j; }

int p2(int p) {
	return (p *= 2) > cnt ? 0 : (p < cnt && lt(iq[p + 1], iq[p]) ? p + 1 : p);
}

void pq_up(int i) {
	int p, q, j;

	for (p = pq[i]; (q = p / 2) && lt(i, j = iq[q]); p = q)
		iq[pq[j] = p] = j;
	iq[pq[i] = p] = i;
}

void pq_dn(int i) {
	int p, q, j;

	for (p = pq[i]; (q = p2(p)) && lt(j = iq[q], i); p = q)
		iq[pq[j] = p] = j;
	iq[pq[i] = p] = i;
}

void pq_add(int i) {
	pq[i] = ++cnt, pq_up(i);
}

int pq_remove_first() {
	int i = iq[1], j = iq[cnt--];

	if (j != i)
		pq[j] = 1, pq_dn(j);
	pq[i] = 0;
	return i;
}

int main() {
	int i, j, a, b;

	scanf("%d", &n);
	memset(ii, -1, n * sizeof *ii), memset(jj, -1, n * sizeof *jj);
	for (i = 0; i < n * 2; i++) {
		scanf("%d", &a), a--;
		aa[i] = a;
		if (ii[a] == -1)
			ii[a] = i;
		else
			jj[a] = i;
	}
	build();
	j = INF;
	while ((i = find(j)) != -1) {
		a = aa[i];
		pq_add(a);
		j = jj[a];
	}
	while (cnt) {
		a = pq_remove_first();
		printf("%d %d ", a + 1, a + 1);
		update(ii[a]);
		j = query(ii[a]);
		while ((i = find(j)) != -1) {
			b = aa[i];
			if (jj[b] < jj[a])
				break;
			pq_add(b);
			j = jj[b];
		}
	}

	printf("\n");
	return 0;
} 