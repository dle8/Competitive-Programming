#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 200000+10
#define maxv 1000000+10
using namespace std;

struct node {
	long l, r, pos;
};

long sqrtn, n, t, occurence[maxv], a[maxn];
long long res[maxn], sum;
node query[maxn];

void add(long val, long sl) {
	sum-=(pow(occurence[val], 2)*val);
	occurence[val]+=sl;
	sum+=(pow(occurence[val], 2)*val);
}

bool cmp(const node&x, const node&y) {
	if (x.l/sqrtn!=y.l/sqrtn) return (x.l/sqrtn<y.l/sqrtn);
	return (x.r<y.r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> t;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, t) {
		cin >> query[i].l >> query[i].r;
		query[i].pos = i;
	}
	
	sqrtn = sqrt(n);
	sort(query+1, query+1+t, cmp);
	
	sum = 0;
	FOR(i, query[1].l, query[1].r) add(a[i], 1);
	res[query[1].pos] = sum;

	FOR(i, 2, t) {
		FOR(j, query[i-1].l, query[i].l-1) add(a[j], -1);
		FOR(j, query[i].l, query[i-1].l-1) add(a[j], 1);
		FOR(j, query[i-1].r+1, query[i].r) add(a[j], 1);
		FOR(j, query[i].r+1, query[i-1].r) add(a[j], -1);
		res[query[i].pos] = sum;
	}
	
	FOR(i, 1, t) cout << res[i] << "\n";
	return 0;
}
