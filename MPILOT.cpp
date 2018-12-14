#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
using namespace std;

typedef long long ll;

long c[maxn], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long x, y;
	ll res = 0;
	cin >> n;
	FOR(i, 1, n) {
		cin >> x >> y;
		res+=y;
		c[i] = x-y;
	}
	
	sort(c+1, c+1+n);
	FOR(i, 1, (n/2)) res+=c[i];
	cout << res;
	return 0;
}
