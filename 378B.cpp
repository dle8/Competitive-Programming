#include <bits/stdc++.h>
#define maxn 100000+10
using namespace std;

long n, a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i] >> b[i];
	for (int i=1; i<=n; i++) {
		if (i<=(n/2) || a[i]<=b[n-i+1]) cout << "1";
		else cout << "0";
	}
	cout << "\n";
	for (int i=1; i<=n; i++) {
		if (i<=(n/2) || b[i]<=a[n-i+1]) cout << "1";
		else cout << "0";
	}
	return 0;
}
