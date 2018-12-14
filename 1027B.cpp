#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long n, q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long x, y, half;
	cin >> n >> q;
	if (n%2==0) half = pow(n, 2)/2;
	else half = pow(n, 2)/2+1;
	FOR(i, 1, q) {
		cin >> x >> y;
		long long k = (x-1)*n+y;
		if ((x+y)%2==0) cout << (k-1)/2+1 << "\n";
		else cout << (k+1)/2+half << "\n";		
	}
	return 0;
}
