#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, count, button;
	cin >> n;
	count = 0;
	for (int i=1; i<=n; i++) {
		cin >> button;
		if (button==0) count++;
	}
	if (n==1) {
		if (button==n) cout << "YES";
		else cout <<"NO";
		return 0;
	}
	if (count!=1) cout << "NO";
	else cout << "YES";
	return  0;
}
