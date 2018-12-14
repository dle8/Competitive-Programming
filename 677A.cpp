#include <bits/stdc++.h>
using namespace std;

long n, h, res;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long height;
	cin >> n >> h;
	res = 0;
	for (int i=1; i<=n; i++) {
		cin >> height;
		if (height<=h) res++;
		else res+=2;
	}
	cout << res;
	return 0;
}
