#include <iostream>
#include <cstdlib>

using namespace std;

long long a[10000+10];
long long n;

long long max(long long a, long long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	int test;
	cin >> test;

	a[0] = 0;
	a[1] = 1;
	
	for (int i=2; i<=10000; i++) {
		if (i%2==0) a[i] = a[i/2];
		else a[i] = a[i/2] + a[i-i/2];
	}

	for (int i=1; i<10000; i++) {
		a[i] = max(a[i-1], a[i]);
	}
	
	for (int i=0; i<test; i++) {
		int n;
		cin >> n;
		if (n%2==0) cout << a[n-1] << "\n";
		else cout << a[n] << "\n";
	}
	
	return 0;
}
