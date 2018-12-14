#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll l, r;
	cin >> l >> r;
	cout << "YES" << "\n";
	for (ll i=l; i<=r-1; i+=2) cout << i << " " << i+1 << "\n";
	return 0;
}
