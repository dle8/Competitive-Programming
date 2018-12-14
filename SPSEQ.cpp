#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 100000+10
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

long f[maxn], increasing[maxn], a[maxn], n, ra[maxn], decreasing[maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

long bs(long length, long key) {
	long d = 1;
	long c = length;
	while (d<=c) {
		long mid = (d+c)/2;
		if (f[mid]>=key) c = mid-1;
		else d = mid+1;
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long index, col, res;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	f[1] = a[1];
	increasing[1] = 1;
	col = 1;
	FOR(i, 2, n) {
		index = bs(col, a[i]);
		increasing[i] = index;
		if (index==col+1) f[++col] = a[i];
		else {
			if (f[index]>a[i]) f[index] = a[i];
		}
	}
	
	FOR(i, 1, n) ra[i] = a[n+1-i];
	memset(f, 0, sizeof(f));
	f[1] = ra[1];
	decreasing[1] = 1;
	col = 1;
	FOR(i, 2, n) {
		index = bs(col, ra[i]);
		decreasing[i] = index;
		if (index==col+1) f[++col] = ra[i];
		else {
			if (f[index]>ra[i]) f[index] = ra[i];
		}
	}
	
	res = 0;
	FOR(i, 1, n) res = max(res, min(increasing[i], decreasing[n+1-i])*2-1);
	cout << res;
	
	return 0;
}
