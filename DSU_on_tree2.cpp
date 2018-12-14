#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
#define oo 1000000000
using namespace std;

struct e {
	long u, v;
};

e edge[maxn];
long ands, n, lab[maxn];
bool check[maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

long getBit(long j, long i) {
	return ((i>>(j-1))&1);
}

long setBit(long x, long j, long i) {
	if (x==0) return (i^(1<<(j-1)));
	return (i|(1<<(j-1)));
}

void generate(long i, long tempPrev) {
	if ((1<<i)>ands) return;
	if (getBit(i+1, ands)==0) {
		FOR(j, 0, 1) {
			long temp = tempPrev;
			if (j==1) temp = setBit(j, i+1, tempPrev);
			if (temp<=n) check[temp] = true;
			generate(i+1, temp);
		}
	}
	else generate(i+1, tempPrev);
}

long getRoot(long u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

long dsu(long r1, long r2) {
	lab[r1]+=lab[r2];
	lab[r2] = r1;
	return lab[r1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, res, maxVertice, r1, r2;
	cin >> n;
	FOR(i, 1, n-1) cin >> edge[i].u >> edge[i].v;

	ands = 0;
	res = -oo;
	while (ands<n) {
		ands++;
		FOR(i, 1, n) {
			check[i] = false;
			lab[i] = -1;
		}
		
		generate(0, ands);
		
		maxVertice = 0;
		//duyet tap canh
		FOR(i, 1, n-1) {
			if (check[edge[i].u] && check[edge[i].v]) {
				r1 = getRoot(edge[i].u);
				r2 = getRoot(edge[i].v);
				if (r1!=r2) maxVertice = max(maxVertice, dsu(r1, r2));
			}
		}
		
		res = max(res, maxVertice*ands);		
	}
	
	return cout << res, 0;
}
