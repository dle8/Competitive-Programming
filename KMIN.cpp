#include <bits/stdc++.h>
#include <algorithm>
#define maxn 50000+10
#define maxc 1000000000
using namespace std;

long long a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, m, k, ai, bi, aj, bj, count;
	
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	
	sort(a+1, a+m+1);
	sort(b+1, b+n+1);
	
	a[m+1] = maxc;
	b[n+1] = maxc;
	
	ai = 1; bi = 1;
	aj = 1; bj = 1;
	
	count = 0;
	while (count<k) {
		count++;
		if (ai==aj && bi==bj) {
			cout << a[ai]+b[bi] << "\n";
			bi++;
			aj++;
		}
		else {
			if ((a[ai]+b[bi])<(a[aj]+b[bj])) {
				cout << a[ai]+b[bi] << "\n";
				bi++;
				if (bi>n) {
					bi = 1;
					ai++;
				}
			}
			else if ((a[ai]+b[bi])==(a[aj]+b[bj])) {
				cout << a[ai]+b[bi] << "\n";
				if (count<k) cout << a[aj]+b[bj] << "\n";
				aj++;
				bi++;
				if (aj>m) {
					aj = 1;
					bj++;
				}
				if (bi>n) {
					bi = 1;
					ai++;
				}
				count++;
			}
			else{
				cout << a[aj]+b[bj] << "\n";
				aj++;
				if (aj>m) {
					aj = 1;
					bj++;
				}
			}
		}
	}
	return 0;
}
