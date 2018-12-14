#include <bits/stdc++.h>
using namespace std;

bool isPrime(long n) {
	if (n==1) return false;
	if (n==2 || n==3) return true;
	for (int i=2; i<=int(sqrt(n)); i++)
		if (n%i==0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long l, r;
	cin >> l >> r;
	for (int i=l; i<=r; i++) {
		if (i>3 && (i%6!=1 && i%6!=5)) continue;
		if (isPrime(i)) cout << i << "\n";
	}
	return 0;
}
