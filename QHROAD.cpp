#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 100000+10
using namespace std;

bool check[maxn];
long lab[maxn], res[maxn], dr[maxn], x[maxn], y[maxn], n, m, q;

long getRoot(long u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void dsu(long r1, long r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long component, r1, r2;
	cin >> n >> m >> q;
	memset(check, false, sizeof(check));
	FOR(i, 1, n) lab[i] = -1;
	FOR(i, 1, m) cin >> x[i] >> y[i];
	FOR(i, 1, q) {
		cin >> dr[i];
		check[dr[i]] = true;
	}
	
	FOR(i, 1, m) {
		if (!check[i]) {
			r1 = getRoot(x[i]);
			r2 = getRoot(y[i]);
			if (r1!=r2) dsu(r1, r2);
		}
	}
	
	memset(check, true, sizeof(check));
	component = 0;
	FOR(i, 1, n) {
		r1 = getRoot(i);
		if (check[r1]) {
			check[r1] = false;
			component++;
		}
	}
	REP(i, q, 1) {
		r1 = getRoot(x[dr[i]]);
		r2 = getRoot(y[dr[i]]);
		res[i] = component;
		if (r1!=r2) {
			dsu(r1, r2);
			component-=1;
		}
	}
	
	FOR(i, 1, q) cout << res[i] << "\n";
	return 0;
}
