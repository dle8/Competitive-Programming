#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, k;
	cin >> n >> k;
	if ((2*n-1<k) || k<3) {
		cout << 0;
		return 0;
	}
	
	cout << (min(n, k-1)-k/2);	
	return 0;
}
