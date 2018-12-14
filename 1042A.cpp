#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 100+10
using namespace std;

long n, m, a[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long maxp = 0, remain, temp;
	cin >> n;
	cin >> m;
	FOR(i, 1, n) {
		cin >> a[i];
		if (a[i]>maxp) maxp = a[i];
	}
	
	remain = 0;
	FOR(i, 1, n) remain+=(maxp-a[i]);
	
	if (m<=remain) cout << maxp << " ";
	else {
		temp = m;
		temp-=remain;
		cout << maxp + temp/n + ((temp%n==0) ? 0 : 1) << " ";
	}
	cout << maxp + m;	
	return 0;
}
