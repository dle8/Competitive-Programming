#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 10000+10
using namespace std;

long a[maxn], n, ft[maxn];

void update(long i, long val) {
	for (; i<=n; i+=(i&(-i))) ft[i]+=val;
}

void process() {
	long u, l, r, val, idex, q;
	memset(ft, 0, sizeof(ft));
	cin >> n >> u;
	n++;
	FOR(i, 1, u) {
		cin >> l >> r >> val;
		l++;
		r++;
		update(l, val);
		update(r+1, -val);
	}
	
	cin >> q;
	FOR(i, 1, q) {
		cin >> idex;
		idex++;
		long sum = 0;
		for (; idex>0; idex-=(idex&(-idex))) sum+=ft[idex];
		cout << sum << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test;
	cin >> test;
	FOR(i, 1, test) process();
	return 0;
}
