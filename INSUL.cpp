#include <bits/stdc++.h>
#include <algorithm>
#define maxn 100000+10
using namespace std;

long n;
long a[maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long sum;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	for (int i=1; i<=n; i++){
		sum+=a[i];
		if (i<=(n/2)) sum+=max(0, a[n+1-i]-a[i]);
	}
	cout << sum;
	return 0;
}
