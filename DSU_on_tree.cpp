#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
using namespace std;

long tcount[maxn], weight[maxn], lab[maxn], n, res;

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
	long u, v, r1, r2;
	cin >> n;
	FOR(i, 1, n) {
		cin >> weight[i];
		lab[i] = -1;
	}
	
	FOR(i, 1, n-1) {
		cin >> u >> v;
		if (weight[u]%2==0 && weight[v]%2==0) {
			r1 = getRoot(u);
			r2 = getRoot(v);
			if (r1!=r2) dsu(r1, r2);
		}
	}
	
	memset(tcount, 0, sizeof(tcount));
	
	res = 0;
	FOR(i, 1, n) {
		r1 = getRoot(i);
		tcount[r1]++;
		if (tcount[r1]>res) res = tcount[r1];
	}
	
	return cout << res, 0;
}
