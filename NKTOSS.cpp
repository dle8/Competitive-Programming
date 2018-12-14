#include <bits/stdc++.h>
using namespace std;

long long res;
long n, k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	res = 0;
	for (int i=k; i<=n; i++) res+=(n-i+1);
	cout << res;
	return 0;
}
