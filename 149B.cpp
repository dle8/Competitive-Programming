#include <bits/stdc++.h>
#define maxn 100000+10
#define maxc 1000000000+10
using namespace std;

long l[maxn], r[maxn], n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long min = maxc;
	long max = -maxc;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i] >> r[i];
		if (r[i]>max) max = r[i];
		if (l[i]<min) min = l[i];
	}
	
	for (int i=1; i<=n; i++) {
		if (l[i]<=min && max<=r[i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
