#include <bits/stdc++.h>
#define maxn 200000+10
using namespace std;

long n, m;
long a[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long r;
	cin >> n >> m;
	r = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		cout << (a[i]+r)/m << " ";
		r = (a[i]+r)%m;
	}
	return 0;
}
