#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mod 1e9+7
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	cin >> f[1] >> f[2];
	cin >> a >> b;
	FOR(i, 3, n) f[n] = (a*f[i-2])%mod;
	FOR(i, 1, n) cin >> x[i];
	
	return 0;
}
