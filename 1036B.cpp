#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

bool divBy2(long long x) {
	return (x%2==0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long x, y, k, q;
	cin >> q;
	FOR(i, 1, q) {
		cin >> x >> y >> k;
		if (abs(x)>k || abs(y)>k) {
			cout << -1 << "\n";
			continue;
		}
		long t = k-abs(x);
		if (y==x && t%2!=0) cout << abs(x)-1+t-1;

		else if (divBy2(abs(y-x)) && divBy2(t)) cout << abs(x)+t;	
		else if (divBy2(abs(y-x)) && !divBy2(t)) cout << abs(x)+t-2;
		else if (!divBy2(abs(y-x)) && divBy2(t)) cout << abs(x)+t-1;
		else cout << abs(x)+t-1;	
		cout << "\n";
	}
	return 0;
}
