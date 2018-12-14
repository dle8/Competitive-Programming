#include <bits/stdc++.h>
#define maxn 10000+10
#define maxp 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1e9
using namespace std;

struct node {
	long s, e, l;
};

node path[maxp];
long lab[maxn], c[maxn], n, p;

bool compare(const node&a, const node&b) {
	return (a.l<b.l);
}

long getRoot(long u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void dsu(long r1, long r2) {
	if (lab[r1]==lab[r2]) {
		lab[r2] = r1;
		lab[r1]--;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p;
	FOR(i, 1, n) lab[i] = -1;
	FOR(i, 1, n) cin >> c[i];
	FOR(i, 1, p) {
		cin >> path[i].s >> path[i].e >> path[i].l;
		path[i].l+=(path[i].l+c[path[i].s]+c[path[i].e]);
	}
	
	sort(path+1, path+1+p, compare);
	
	long res = 0;
	FOR(i, 1, p) {
		long r1 = getRoot(path[i].s);
		long r2 = getRoot(path[i].e);
		if (r1!=r2) {
			dsu(r1, r2);
			res+=path[i].l;
		}
	}
	
	long min = oo;
	FOR(i, 1, n) if (c[i]<min) min = c[i];
	cout << res + min;
	
	return 0;
}
