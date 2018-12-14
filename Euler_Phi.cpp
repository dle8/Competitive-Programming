#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

long eulerPhi(long n) {
	if (n==0) return 0;
	long euler = n;
	FOR(i, 2, sqrt(n)) {
		if (n%i==0) {
			euler-=euler/i;
			while (n%i==0) n/=i;
		}
	}
	if (n>1) euler-=euler/n;//in case n is a prime -> there is no i from 2 to sqrt(n) that is divisible by n
	return euler;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test, n;
	cin >> test;
	FOR(i, 1, test) {
		cin >> n;
		cout << eulerPhi(n) << "\n";
	}
	return 0;
}
