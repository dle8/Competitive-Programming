#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
#define maxm 100000+10
using namespace std;

typedef long long ll;

long n;

struct node {
	long u, v, c;
	
	bool operator<(const node& p) {
		return (c<p.c);
	}
};

struct DSU {//union based on height of the tree
	long lab[maxn];
	
	DSU() {
		FOR(i, 1, n) lab[i] = -1;
	}
	
	long getRoot(long u) {
		if (lab[u]<0) return u;
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	
	void merge(long roota, long rootb) {
		if (lab[roota]==lab[rootb]) {
			lab[roota]--;
			lab[rootb] = roota;
			return;
		}
		if (lab[roota]<lab[rootb]) lab[rootb] = roota;
		else lab[roota] = rootb;
	}
};

node edge[maxm];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long r1, r2, m, u, v, c;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> u >> v >> c;
		edge[i].u = u;
		edge[i].v = v;
		edge[i].c = c;
	}
	
	sort(edge+1, edge+1+m);
	
	DSU dsu;
	ll weight = 0;
	FOR(i, 1, m) {
		r1 = dsu.getRoot(edge[i].u);
		r2 = dsu.getRoot(edge[i].v);
		if (r1!=r2) {
			weight+=edge[i].c;
			dsu.merge(r1, r2);
		}
	}
	
	cout << weight;
	return 0;
}
